#!/bin/sh

if [ "$1" != "" ]; then
    signal_ver="$1"
else
    echo "Error: not set signal version"
    echo "Usage: ./get_signal_dep_versions.sh <signal version>"
	exit 1
fi

echo "Signal-Desktop-${signal_ver} dependencies:"
echo ""

ftp -o /tmp/package.json "https://raw.githubusercontent.com/signalapp/Signal-Desktop/v${signal_ver}/package.json" > /dev/null 2>&1

# Node
node_version=$(awk /'"node":'/'{print $2}' /tmp/package.json | head -n 1 | sed 's/"//g')
node_major_version=${node_version%%.*}
echo "* node: lang/nodejs${node_major_version}"
accepted_node_version=$(make -C .. -V NODE_VERSIONS_ACCEPTED)
if [ "${accepted_node_version}" != "${node_major_version}" ]; then
    echo "   ! Need nodejs${node_major_version}, but electron.mk used NODE_VERSIONS_ACCEPTED=${accepted_node_version}"
fi

# Electron
electron_version=$(grep '"electron":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
electron_major_version=${electron_version%%.*}
echo "* electron: wip/electron${electron_major_version}"
used_electron_version=$(make -C .. -V ELECTRON_VER)
used_electron_major=${used_electron_version%%.*}
if [ "${used_electron_major}" != "${electron_major_version}" ]; then
    echo "   ! Need electron${electron_major_version}, but used wip/electron${used_electron_major}/electron.mk"
fi

# lightningcss
lightningcss_version=$(ftp -o - "https://raw.githubusercontent.com/signalapp/Signal-Desktop/v${signal_ver}/pnpm-lock.yaml" | sed -n 's/.*lightningcss@\([^)]*\)).*/\1/p' | head -1)
echo "* lightningcss: ${lightningcss_version}"

# ringrtc
ringrtc_rebuild=0
ringrtc_version=$(grep '@signalapp/ringrtc"' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "* wip/ringrtc ${ringrtc_version}"
used_ringrtc_version=$(make -C .. -V RINGRTC_VER)
if [ "${used_ringrtc_version}" != "${ringrtc_version}" ]; then
    echo "   ! Need ringrtc-${ringrtc_version}, but used ${used_ringrtc_version}"
    ringrtc_rebuild=1
fi

# ringrtc internal dependencies
## libsignal
ftp -o /tmp/ringrtc_deps "https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/Cargo.lock" > /dev/null 2>&1
libsignal_version=$(sed -n 's/.*github.com\/signalapp\/libsignal?tag=v\([^#]*\)#.*/\1/p' /tmp/ringrtc_deps | head -1)
echo " - libsignal: ${libsignal_version}"
used_libsignal_version=$(make -C .. -V LIBSIGNAL_VER)
if [ "${used_libsignal_version}" != "${libsignal_version}" ]; then
    echo "   ! Need libsignal-${libsignal_version}, but used ${used_libsignal_version}"
    ringrtc_rebuild=1
fi

## libcubeb
libcubeb_version=$(grep -A2 'cubeb-sys' /tmp/ringrtc_deps | sed -n 's/^version = "\([^"]*\)".*/\1/p')
echo " - libcubeb: ${libcubeb_version}"
used_libcubeb_version=$(make -C .. -V LIBCUBEB_VER)
if [ "${used_libcubeb_version}" != "${libcubeb_version}" ]; then
    echo "   ! Need libcubeb-${libcubeb_version}, but used ${used_libcubeb_version}"
    ringrtc_rebuild=1
fi

## webrtc
webrtc_version=$(ftp -o - "https://raw.githubusercontent.com/signalapp/ringrtc/v${ringrtc_version}/config/version.properties" | grep 'webrtc.version' | awk -F '=' '{print $2}')
echo " - webrtc: ${webrtc_version}"
used_webrtc_version=$(make -C .. -V WEBRTC_VER)
if [ "${used_webrtc_version}" != "${webrtc_version}" ]; then
    echo "   ! Need webrtc-${webrtc_version}, but used ${used_webrtc_version}"
    ringrtc_rebuild=1
fi
ftp -o /tmp/webrtc_deps "https://raw.githubusercontent.com/signalapp/webrtc/${webrtc_version}/DEPS" > /dev/null 2>&1

## boringssl
boringssl_hash=$(grep 'boringssl.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - boringssl: ${boringssl_hash}"
used_boringssl_version=$(make -C .. -V BORINGSSL_VER)
if [ "${used_boringssl_version}" != "${boringssl_hash}" ]; then
    echo "   ! Need boringssl-${boringssl_hash}, but used ${used_boringssl_version}"
    ringrtc_rebuild=1
fi

## build
build_hash=$(grep 'build@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - build: ${build_hash}"
used_build_version=$(make -C .. -V BUILD_VER)
if [ "${used_build_version}" != "${build_hash}" ]; then
    echo "   ! Need build-${build_hash}, but used ${used_build_version}"
    ringrtc_rebuild=1
fi

## buildtools
buildtools_hash=$(grep 'buildtools@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - buildtools: ${buildtools_hash}"
used_buildtools_version=$(make -C .. -V BUILDTOOLS_VER)
if [ "${used_buildtools_version}" != "${buildtools_hash}" ]; then
    echo "   ! Need buildtools-${buildtools_hash}, but used ${used_buildtools_version}"
    ringrtc_rebuild=1
fi

## catapult
catapult_hash=$(grep 'catapult.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - catapult: ${catapult_hash}"
used_catapult_version=$(make -C .. -V CATAPULT_VER)
if [ "${used_catapult_version}" != "${catapult_hash}" ]; then
    echo "   ! Need catapult-${catapult_hash}, but used ${used_catapult_version}"
    ringrtc_rebuild=1
fi

## icu
icu_hash=$(grep 'icu.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - icu: ${icu_hash}"
used_icu_version=$(make -C .. -V ICU_VER)
if [ "${used_icu_version}" != "${icu_hash}" ]; then
    echo "   ! Need icu-${icu_hash}, but used ${used_icu_version}"
    ringrtc_rebuild=1
fi

## libjpeg_turbo
libjpeg_turbo_hash=$(grep 'libjpeg_turbo.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - libjpeg_turbo: ${libjpeg_turbo_hash}"
used_libjpeg_turbo_version=$(make -C .. -V LIBJPEG_TURBO_VER)
if [ "${used_libjpeg_turbo_version}" != "${libjpeg_turbo_hash}" ]; then
    echo "   ! Need libjpeg_turbo-${libjpeg_turbo_hash}, but used ${used_libjpeg_turbo_version}"
    ringrtc_rebuild=1
fi

## libsrtp
libsrtp_hash=$(grep 'libsrtp.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - libsrtp: ${libsrtp_hash}"
used_libsrtp_version=$(make -C .. -V LIBSRTP_VER)
if [ "${used_libsrtp_version}" != "${libsrtp_hash}" ]; then
    echo "   ! Need libsrtp-${libsrtp_hash}, but used ${used_libsrtp_version}"
    ringrtc_rebuild=1
fi

## libvpx
libvpx_hash=$(grep 'libvpx.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - libvpx: ${libvpx_hash}"
used_libvpx_version=$(make -C .. -V LIBVPX_VER)
if [ "${used_libvpx_version}" != "${libvpx_hash}" ]; then
    echo "   ! Need libvpx-${libvpx_hash}, but used ${used_libvpx_version}"
    ringrtc_rebuild=1
fi

## libyuv
libyuv_hash=$(grep 'libyuv.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - libyuv: ${libyuv_hash}"
used_libyuv_version=$(make -C .. -V LIBYUV_VER)
if [ "${used_libyuv_version}" != "${libyuv_hash}" ]; then
    echo "   ! Need libyuv-${libyuv_hash}, but used ${used_libyuv_version}"
    ringrtc_rebuild=1
fi

## nasm
nasm_hash=$(grep 'nasm.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - nasm: ${nasm_hash}"
used_nasm_version=$(make -C .. -V NASM_VER)
if [ "${used_nasm_version}" != "${nasm_hash}" ]; then
    echo "   ! Need nasm-${nasm_hash}, but used ${used_nasm_version}"
    ringrtc_rebuild=1
fi

## opus
opus_hash=$(grep 'opus.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - opus: ${opus_hash}"
used_opus_version=$(make -C .. -V OPUS_VER)
if [ "${used_opus_version}" != "${opus_hash}" ]; then
    echo "   ! Need opus-${opus_hash}, but used ${used_opus_version}"
    ringrtc_rebuild=1
fi

## perfetto
perfetto_hash=$(grep 'perfetto.git' /tmp/webrtc_deps | awk -F '+' '{print $4}' | sed -e "s# ##g" -e "s#',##" -e "s#'##")
echo " - perfetto: ${perfetto_hash}"
used_perfetto_version=$(make -C .. -V PERFETTO_VER)
if [ "${used_perfetto_version}" != "${perfetto_hash}" ]; then
    echo "   ! Need perfetto-${perfetto_hash}, but used ${used_perfetto_version}"
    ringrtc_rebuild=1
fi

## protobuf-javascript
protobuf_javascript_hash=$(grep "protobuf-javascript' + '@'" /tmp/webrtc_deps | awk -F '+' '{print $4}' | sed -e "s# ##g" -e "s#',##" -e "s#'##")
echo " - protobuf-javascript: ${protobuf_javascript_hash}"
used_protobuf_javascript_version=$(make -C .. -V PROTOBUFJS_VER)
if [ "${used_protobuf_javascript_version}" != "${protobuf_javascript_hash}" ]; then
    echo "   ! Need protobuf-javascript-${protobuf_javascript_hash}, but used ${used_protobuf_javascript_version}"
    ringrtc_rebuild=1
fi

## re2
re2_hash=$(grep 're2.git@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - re2: ${re2_hash}"
used_re2_version=$(make -C .. -V RE2_VER)
if [ "${used_re2_version}" != "${re2_hash}" ]; then
    echo "   ! Need re2-${re2_hash}, but used ${used_re2_version}"
    ringrtc_rebuild=1
fi

## testing
testing_hash=$(grep 'testing@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - testing: ${testing_hash}"
used_testing_version=$(make -C .. -V TESTING_VER)
if [ "${used_testing_version}" != "${testing_hash}" ]; then
    echo "   ! Need testing-${testing_hash}, but used ${used_testing_version}"
    ringrtc_rebuild=1
fi

## third_party
third_party_hash=$(grep 'third_party@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - third_party: ${third_party_hash}"
used_third_party_version=$(make -C .. -V THIRD_PARTY_VER)
if [ "${used_third_party_version}" != "${third_party_hash}" ]; then
    echo "   ! Need third_party-${third_party_hash}, but used ${used_third_party_version}"
    ringrtc_rebuild=1
fi

## tools
tools_hash=$(grep 'src/tools@' /tmp/webrtc_deps | awk -F '@' '{print $2}' | sed -e "s#',##" -e "s#'##")
echo " - tools: ${tools_hash}"
used_tools_version=$(make -C .. -V TOOLS_VER)
if [ "${used_tools_version}" != "${tools_hash}" ]; then
    echo "   ! Need tools-${tools_hash}, but used ${used_tools_version}"
    ringrtc_rebuild=1
fi

# libsignal-node
libsignal_node_rebuild=0
libsignal_node_version=$(grep '@signalapp/libsignal-client' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "* wip/libsignal ${libsignal_node_version}"
used_libsignal_node_version=$(make -C .. -V LIBSIGNAL_NODE_VER)
if [ "${used_libsignal_node_version}" != "${libsignal_node_version}" ]; then
    echo "   ! Need libsignal-node-${libsignal_node_version}, but used ${used_libsignal_node_version}"
    libsignal_node_rebuild=1
fi

# libsignal-node internal dependencies
## boring-signal
ftp -o /tmp/libsignal_toml "https://raw.githubusercontent.com/signalapp/libsignal/v${libsignal_node_version}/Cargo.toml" > /dev/null 2>&1
boring_signal_version=$(sed -n 's/^boring-signal = .*signal-v\([^"]*\)".*/\1/p' /tmp/libsignal_toml)
echo " - boring-signal: ${boring_signal_version}"
used_boring_signal_version=$(make -C .. -V BORING_SIGNAL_VER)
if [ "${used_boring_signal_version}" != "${boring_signal_version}" ]; then
    echo "   ! Need boring-signal-${boring_signal_version}, but used ${used_boring_signal_version}"
    libsignal_node_rebuild=1
fi

## boring hash
if command -v lynx >/dev/null 2>&1; then
    boring_hash=$(lynx -dump "https://github.com/signalapp/boring/tree/signal-v${boring_signal_version}/boring-sys/deps" | sed -n 's|.*google/boringssl/tree/\(.*\)|\1|p' | head -1)
    echo " - boring-hash: ${boring_hash}"
    used_boring_hash=$(make -C .. -V BORING_HASH)
    if [ "${used_boring_hash}" != "${boring_hash}" ]; then
        echo "   ! Need boring-signal-${boring_hash}, but used ${used_boring_hash}"
        libsignal_node_rebuild=1
    fi
else
    echo "   ! SKIP boring-hash: lynx not found"
fi

## spqr
spqr_version=$(sed -n 's/^spqr = .*"v\([^"]*\)".*/\1/p' /tmp/libsignal_toml)
echo " - spqr: ${spqr_version}"
used_spqr_version=$(make -C .. -V SPQR_VER)
if [ "${used_spqr_version}" != "${spqr_version}" ]; then
    echo "   ! Need spqr-${spqr_version}, but used ${used_spqr_version}"
    libsignal_node_rebuild=1
fi

# node-sqlcipher
node_sqlcipher_rebuild=0
sqlcipher_version=$(grep '"@signalapp/sqlcipher":' /tmp/package.json | awk -F ":" '{print $2}' | sed -E 's#("|,| )##g')
echo "* wip/node-sqlcipher ${sqlcipher_version}"
used_sqlcipher_version=$(make -C .. -V SQLCIPHER_VER)
if [ "${used_sqlcipher_version}" != "${sqlcipher_version}" ]; then
    echo "   ! Need node-sqlcipher-${sqlcipher_version}, but used ${used_sqlcipher_version}"
    node_sqlcipher_rebuild=1
fi

# node-sqlcipher internal dependencies
## signal-sqlcipher-extension
ftp -o /tmp/node_sqlcipher_extension "https://raw.githubusercontent.com/signalapp/node-sqlcipher/refs/tags/v${sqlcipher_version}/deps/extension/Cargo.toml" > /dev/null 2>&1
sqlcipher_ext_version=$(sed -n 's/^version = "\([^"]*\)".*/\1/p' /tmp/node_sqlcipher_extension)
echo " - signal-sqlcipher-extension: ${sqlcipher_ext_version}"
used_sqlcipher_ext_version=$(make -C .. -V SQLCIPHER_EXT_VER)
if [ "${sqlcipher_ext_version}" != "${used_sqlcipher_ext_version}" ]; then
    echo "   ! Need signal-sqlcipher-extension-${sqlcipher_ext_version}, but used ${used_sqlcipher_ext_version}"
    node_sqlcipher_rebuild=1
fi

## signal-tokenizer
signal_tokenizer_hash=$(sed -n 's/^signal-tokenizer.*rev = "\(.*\)".*/\1/p' /tmp/node_sqlcipher_extension)
echo " - signal-tokenizer: ${signal_tokenizer_hash}"
used_signal_tokenizer_hash=$(make -C .. -V SIGNAL_TOKENIZER_HASH)
if [ "${signal_tokenizer_hash}" != "${used_signal_tokenizer_hash}" ]; then
    echo "   ! Need signal-tokenizer-${signal_tokenizer_hash}, but used ${used_signal_tokenizer_hash}"
    node_sqlcipher_rebuild=1
fi


if [ "${ringrtc_rebuild}" -eq 1 ]; then
    echo "Need to update: wip/ringrtc"
fi
if [ "${libsignal_node_rebuild}" -eq 1 ]; then
    echo "Need to update: wip/libsignal"
fi
if [ "${node_sqlcipher_rebuild}" -eq 1 ]; then
    echo "Need to update: wip/node-sqlcipher"
fi

echo ""
printf "Update wip/signal-desktop/versions.mk: [y/n] "
read -r answer
if [ "$answer" = "y" ]; then
    cat <<EOF > ../versions.mk
# \$NetBSD$

SIGNAL_VERSION=		${signal_ver}
ELECTRON_MAJOR_VER=	${electron_major_version}
NODE_MAJOR=		${node_major_version}
LIGHTNINGCSS_VER=	${lightningcss_version}
RINGRTC_VER=		${ringrtc_version}
LIBSIGNAL_VER=		${libsignal_version}
LIBCUBEB_VER=		${libcubeb_version}
WEBRTC_VER=		${webrtc_version}
BORINGSSL_VER=		${boringssl_hash}
BUILD_VER=		${build_hash}
BUILDTOOLS_VER=		${buildtools_hash}
CATAPULT_VER=		${catapult_hash}
ICU_VER=		${icu_hash}
LIBJPEG_TURBO_VER=	${libjpeg_turbo_hash}
LIBSRTP_VER=		${libsrtp_hash}
LIBVPX_VER=		${libvpx_hash}
LIBYUV_VER=		${libyuv_hash}
NASM_VER=		${nasm_hash}
OPUS_VER=		${opus_hash}
PERFETTO_VER=		${perfetto_hash}
PROTOBUFJS_VER=		${protobuf_javascript_hash}
RE2_VER=		${re2_hash}
TESTING_VER=		${testing_hash}
THIRD_PARTY_VER=	${third_party_hash}
TOOLS_VER=		${tools_hash}
LIBSIGNAL_NODE_VER=	${libsignal_node_version}
BORING_SIGNAL_VER=	${boring_signal_version}
BORING_HASH=		${boring_hash}
SPQR_VER=		${spqr_version}
SQLCIPHER_VER=		${sqlcipher_version}
SQLCIPHER_EXT_VER=	${sqlcipher_ext_version}
SIGNAL_TOKENIZER_HASH=	${signal_tokenizer_hash}
EOF
    echo ../versions.mk updated.
fi
