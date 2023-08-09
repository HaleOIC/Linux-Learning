#!/bin/sh

# Display usage
cpack_usage()
{
  cat <<EOF
Usage: $0 [options]
Options: [defaults in brackets after descriptions]
  --help            print this message
  --version         print cmake installer version
  --prefix=dir      directory in which to install
  --include-subdir  include the Demo8-1.0.1-Linux subdirectory
  --exclude-subdir  exclude the Demo8-1.0.1-Linux subdirectory
  --skip-license    accept license
EOF
  exit 1
}

cpack_echo_exit()
{
  echo $1
  exit 1
}

# Display version
cpack_version()
{
  echo "Demo8 Installer Version: 1.0.1, Copyright (c) Humanity"
}

# Helper function to fix windows paths.
cpack_fix_slashes ()
{
  echo "$1" | sed 's/\\/\//g'
}

interactive=TRUE
cpack_skip_license=FALSE
cpack_include_subdir=""
for a in "$@"; do
  if echo $a | grep "^--prefix=" > /dev/null 2> /dev/null; then
    cpack_prefix_dir=`echo $a | sed "s/^--prefix=//"`
    cpack_prefix_dir=`cpack_fix_slashes "${cpack_prefix_dir}"`
  fi
  if echo $a | grep "^--help" > /dev/null 2> /dev/null; then
    cpack_usage
  fi
  if echo $a | grep "^--version" > /dev/null 2> /dev/null; then
    cpack_version
    exit 2
  fi
  if echo $a | grep "^--include-subdir" > /dev/null 2> /dev/null; then
    cpack_include_subdir=TRUE
  fi
  if echo $a | grep "^--exclude-subdir" > /dev/null 2> /dev/null; then
    cpack_include_subdir=FALSE
  fi
  if echo $a | grep "^--skip-license" > /dev/null 2> /dev/null; then
    cpack_skip_license=TRUE
  fi
done

if [ "x${cpack_include_subdir}x" != "xx" -o "x${cpack_skip_license}x" = "xTRUEx" ]
then
  interactive=FALSE
fi

cpack_version
echo "This is a self-extracting archive."
toplevel="`pwd`"
if [ "x${cpack_prefix_dir}x" != "xx" ]
then
  toplevel="${cpack_prefix_dir}"
fi

echo "The archive will be extracted to: ${toplevel}"

if [ "x${interactive}x" = "xTRUEx" ]
then
  echo ""
  echo "If you want to stop extracting, please press <ctrl-C>."

  if [ "x${cpack_skip_license}x" != "xTRUEx" ]
  then
    more << '____cpack__here_doc____'
The MIT License (MIT)

Copyright (c) 2013 Joseph Pan(http://hahack.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

____cpack__here_doc____
    echo
    while true
      do
        echo "Do you accept the license? [yn]: "
        read line leftover
        case ${line} in
          y* | Y*)
            cpack_license_accepted=TRUE
            break;;
          n* | N* | q* | Q* | e* | E*)
            echo "License not accepted. Exiting ..."
            exit 1;;
        esac
      done
  fi

  if [ "x${cpack_include_subdir}x" = "xx" ]
  then
    echo "By default the Demo8 will be installed in:"
    echo "  \"${toplevel}/Demo8-1.0.1-Linux\""
    echo "Do you want to include the subdirectory Demo8-1.0.1-Linux?"
    echo "Saying no will install in: \"${toplevel}\" [Yn]: "
    read line leftover
    cpack_include_subdir=TRUE
    case ${line} in
      n* | N*)
        cpack_include_subdir=FALSE
    esac
  fi
fi

if [ "x${cpack_include_subdir}x" = "xTRUEx" ]
then
  toplevel="${toplevel}/Demo8-1.0.1-Linux"
  mkdir -p "${toplevel}"
fi
echo
echo "Using target directory: ${toplevel}"
echo "Extracting, please wait..."
echo ""

# take the archive portion of this file and pipe it to tar
# the NUMERIC parameter in this command should be one more
# than the number of lines in this header file
# there are tails which don't understand the "-n" argument, e.g. on SunOS
# OTOH there are tails which complain when not using the "-n" argument (e.g. GNU)
# so at first try to tail some file to see if tail fails if used with "-n"
# if so, don't use "-n"
use_new_tail_syntax="-n"
tail $use_new_tail_syntax +1 "$0" > /dev/null 2> /dev/null || use_new_tail_syntax=""

extractor="pax -r"
command -v pax > /dev/null 2> /dev/null || extractor="tar xf -"

tail $use_new_tail_syntax +170 "$0" | gunzip | (cd "${toplevel}" && ${extractor}) || cpack_echo_exit "Problem unpacking the Demo8-1.0.1-Linux"

echo "Unpacking finished successfully"

exit 0
#-----------------------------------------------------------
#      Start of TAR.GZ file
#-----------------------------------------------------------;
� ��d �\l��4i�4��HZ�%U[ǎ��PJ�4nԦY�@����>'��w��LD!#"*��6m�1Me��&�I�T����4X+!`�:�J逑�m�6Vｻ�u�^|M`m���H����~���ݽ�}�/.+�*#��4�Z��VZ�D�#���pS��[�t�+F��领�2(����-�O�Q��#���O��>�+�$tYUr�ʖ���9q�p8��P��P�	��+[������-w�Zb�nooGp�y��o,
�{�ǅ/5e�!IK�5��՞}2&�����;ՏL4|�
������b�9t7�J�Űg��@��c���苍���N�:7��G�f|[&ǣ�c�Ρ�sʉ���W����צ|M��6Ggg|��I��#�O�E�=���@*�{l�(����fzڽs��ƾx^��|�1�և�F2��2��|��A�����fL^��
��H�����K+������A�]�ҳ�����s�3ʼX(�WV�g	�|�:㘓?'�@֙��*�m��`���-C�P 7���8��f�A8Ӥ�Хa��.�@<��\�L$�LFRp���R �m=�[$��d55+i��$
)M�\�N�h���ީ`��lQ�=��s��៦�54]Euaȁ���ː?p�/[�j��(���'(e�(����ϑ�n`�C�Kԉ��%xV=@>����?K)�����n?�u}2K��T��_��ɲI�T����rX}b�{�	��g�o��>TJ_@��� �)�^�2����q�n������1	��kvmTF�F�~3�J�Z�tZ���C7�&�=���x��eT��^�,�u	P�y�e�s��N�N�ܒfim��Z���x�g�a�N�z�
������v���Q\sR=՛�z��t��S��%��J��R����z�T���N����ד���n�7���3�.d�P����`x{hyN���SF�R�iH'�Ӳ����\�	��@c�^��NknϨ�{�|�'��<�fO���K8�}>1����u<Ge��>���2d]~��]F��Hod��J��G��#���+�!~��~���a�[�1ټ�C���ȏ�`B 7w]Ȉ��9�aQHɊ���PV�=���f�{Og�N��S5��$t����&�9]�z��L���+���@2�BLђ�d�8<�e���y��pY��|ͯ���Qo���[D���ü����J�g���_�j�C��&�@�u�Y�:�,|�u8m�[ן��2��u�um7i�[��,|��i)r�.\�p�X�o��*cG�ۀP�k���p:6��J�[D��	̞)ԍa�[g����,
�i�H�)�=F��b��H����!�Z�Y>N�3�:&}�^mM�>�?�Pl���ع���hh2�Z���_���8��_Rߺ�F{0����h�u��1���M+`6}Y�o�(�;I)��@2�6�GȦK������{y�,ƽ;sI_�<OTΦ�z�>���v�����ƶ?ANc����#۟ĉ��
��$�W��4� ֵ�_�
Vp�л����C�z����A/�r��Wp�n_A�^5���	.�ʙ�묹���D��Q�N��&+�W��L�Ul<:M��4O�y�����{S��s��,7=���Mkj�	fɧ�Y*��m<5��!�-�nZ8A��T���k'�����+��x-g�.\�p�.\����_y�r�Ò��U��K�^ԗ�;y�s/gUERt�k�w�C����q���xuH����㚨�xT7�?�m�r����K����-�F���C�?*���b�,��Ӆ��az ���B���f��2����H��g`
�2��:���n�GA��&��]+j��UU��k����V�� >`9�&|�oԍ��>)�i|�����Q�����$�?������҅.\�p��?����~,A��R��MZv��Z��W�5�����L�_/�؀	�>x�����C��EﻔVQ
1!���x����a?��>~7P����'�����|����]��}e]��Qj�0�o`��S4��4]2N�
 ��Y�?��nJ������.2��N������4�(��w�'����z�iO��J;?L����(w��Տ��8�Bq��v�1v�2�W�#��с���I��*4z�SZ�C��y��mZ
���d����"8��G�Q'l�)��J�eo�J�e?e�k��u8��s�8r+�-� C�=+��5@��Γ�[�o8��{���S[� />)�*�o���kP#�4�O���ÓT�m�o����|���7�u�֓�sѡ]U����<�?��9��'4=P� �qY���9=�Jh�^�3B�8��dR�j\LI]�r��F	5�MK�������_DMGIѵdD�
�|&3�U,)K�6Q��O��G
�z��F�hW��︿�mo�N����'Dc47�у��{������ڵ?�+����
�H�y!�� ���p�`c�_lt�D��$�,z^���̩ �$IB�>���!���خ��x.Gu�������.rZ�L���l\5n��eKJY�N��I�jk�'���s�(�Qp&�53��MmK��Ƃ�,��I-p5�i`@�'9)�h�����Xo���\ʴa�=S�qQbFN���!^�?Y�Y�o��� l��zd�=v���E73�l\�m�<�����s�}�;�߇������s�)֟l��&U��a}
t��IKž����W��
�[ ��_A���a�ֵPCC�ZҰ
���@<��X����$S>��oS�v���6�~�~M	���wo	�! v�����~;�f�ٰ����N���?�����u��}X ��ֳ��9���Ռ<��DL�>o�Ì<;^g���4�������_/P�y|�@��C�۬/-_�Ћ��Y�a�|���Bf߃~1��C��RFƑ�qa�;����n[��_�1{o�R�����s��7`�������Wz�ЯsзҒ{GP}��= �G��N{G�#&��_��w5�t��y�;BV�|R��{�}���#�Fw��k��������(c��߂������Cx�#xƸ�\44�IU�����gӢ�R���������)�v��۰�_�W�R��������on�z��lN��&%y5k������I�.+9�{���_���؊�H<�yF�7ڳ�s_����}=|�!��g���ŧ\��?R��m`��?��y���n�����z9e\��j�����i�4�K��o�xڸ#H�F� ~�[xYы΁��y��%%)��Յ.���oP��� \  