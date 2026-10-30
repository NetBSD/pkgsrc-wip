# $NetBSD: $

DISTNAME=		vscode-1.143.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=		${PKGVERSION_NOREV}
SOURCE_COMMIT_HASH=	d956e8a6ac5d904486557eea07e1d6bd62a4d36f

NODE_MODULES=		vscode-node_modules-${PKGVERSION_NOREV}.tar.gz
MASTER_SITES+=		https://distfiles.borderland.hu/
DISTFILES+=		${NODE_MODULES}
DISTFILES+=		${DEFAULT_DISTFILES}

# os-proxy-resolver
GITHUB_SUBMODULES+=	microsoft os-proxy-resolver v0.4.0 os-proxy-resolver
CARGO_WRKSRC=		${WRKSRC}/os-proxy-resolver/npm/native
.include "cargo-depends.mk"

COPILOT_CLI_VERSION=	1.0.73

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://code.visualstudio.com/
COMMENT=		The Open Source build of Visual Studio Code (vscode) editor
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		zip gmake pkg-config pax bash tar patch

USE_CXX_FEATURES+=	c++20

TOOL_DEPENDS+=		jq-[0-9]*:../../devel/jq
TOOL_DEPENDS+=		ripgrep-[0-9]*:../../textproc/ripgrep
TOOL_DEPENDS+=		wabt-[0-9]*:../../wip/wabt

.include "../../wip/electron43/electron.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_MESSAGE.vars=	Fixing variables
SUBST_FILES.vars+=	node_modules/@vscode/os-proxy-resolver-pkgsrc-x64/package.json
SUBST_FILES.vars+=	src/vs/platform/native/electron-main/nativeHostMainService.ts
SUBST_FILES.vars+=	code-oss.sh
SUBST_VARS.vars+=	PREFIX OPSYS LOWER_OPSYS ELECTRON_ARCH

SUBST_CLASSES+=		npm
SUBST_STAGE.npm=	pre-configure
SUBST_MESSAGE.npm=	Prepare npm wrapper script
SUBST_FILES.npm+=	npm-wrapper.sh
SUBST_SED.npm+=		-e 's,%%COPILOT_CLI_VERSION%%,${COPILOT_CLI_VERSION},g'
SUBST_SED.npm+=		-e 's,%%WRKSRC%%,${WRKSRC},g'
SUBST_SED.npm+=		-e 's,%%ELECTRON_ARCH%%,${ELECTRON_ARCH},g'
SUBST_SED.npm+=		-e 's,%%NPM_REAL%%,${PREFIX}/bin/npm,g'

SUBST_CLASSES+=		res
SUBST_STAGE.res=	pre-configure
SUBST_MESSAGE.res=	Fixing resource files
SUBST_FILES.res+=	resources/completions/bash/code
SUBST_FILES.res+=	resources/completions/zsh/_code
SUBST_FILES.res+=	resources/linux/code.appdata.xml
SUBST_FILES.res+=	resources/linux/code.desktop
SUBST_FILES.res+=	resources/linux/code-url-handler.desktop
SUBST_SED.res+=		-e 's,@@NAME_SHORT@@,Code,g'
SUBST_SED.res+=		-e 's,@@NAME_LONG@@,Code - OSS,g'
SUBST_SED.res+=		-e 's,@@NAME@@,code-oss,g'
SUBST_SED.res+=		-e 's,@@ICON@@,com.visualstudio.code.oss,g'
SUBST_SED.res+=		-e 's,@@EXEC@@,code-oss,g'
SUBST_SED.res+=		-e 's,@@LICENSE@@,MIT,g'
SUBST_SED.res+=		-e 's,@@URLPROTOCOL@@,vscode,g'
SUBST_SED.res+=		-e 's,@@APPNAME@@,code-oss,g'

REPLACE_BASH=		src/vs/base/node/terminateProcess.sh
REPLACE_BASH+=		src/vs/base/node/cpuUsage.sh
REPLACE_BASH+=		node_modules/jschardet/scripts/show-size-changes.sh
REPLACE_BASH+=		node_modules/jschardet/scripts/run-workflow.sh

REPLACE_NODEJS=		extensions/copilot/node_modules/@anthropic-ai/sdk/bin/cli
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot-netbsd-x64/app.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot-netbsd-x64/index.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot-netbsd-x64/napi-oop-runtime/node_modules/napi-oop-runtime/dist/codegen-cli.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot-netbsd-x64/npm-loader.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot-netbsd-x64/webview/node_modules/@webviewjs/webview/cli/index.mjs
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot/npm-loader.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/@grpc/proto-loader/build/bin/proto-loader-gen-types.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/acorn/bin/acorn
REPLACE_NODEJS+=	extensions/copilot/node_modules/async-listener/node_modules/semver/bin/semver
REPLACE_NODEJS+=	extensions/copilot/node_modules/cls-hooked/node_modules/semver/bin/semver
REPLACE_NODEJS+=	extensions/copilot/node_modules/loose-envify/cli.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/markdown-it/bin/markdown-it.mjs
REPLACE_NODEJS+=	extensions/copilot/node_modules/semver/bin/semver.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/which/bin/node-which
REPLACE_NODEJS+=	extensions/node_modules/typescript/bin/tsc
REPLACE_NODEJS+=	extensions/node_modules/typescript/bin/tsserver
REPLACE_NODEJS+=	node_modules/@devcontainers/cli/devcontainer.js
REPLACE_NODEJS+=	node_modules/@vscode/sandbox-runtime/dist/cli.js
REPLACE_NODEJS+=	node_modules/@vscode/vscode-languagedetection/cli/index.js
REPLACE_NODEJS+=	node_modules/chrome-remote-interface/bin/client.js
REPLACE_NODEJS+=	node_modules/is-docker/cli.js
REPLACE_NODEJS+=	node_modules/mkdirp/bin/cmd.js
REPLACE_NODEJS+=	node_modules/opentype.js/bin/ot
REPLACE_NODEJS+=	node_modules/rc/cli.js
REPLACE_NODEJS+=	node_modules/semver/bin/semver.js

MAKE_ENV+=		ELECTRON_SKIP_BINARY_DOWNLOAD=1
MAKE_ENV+=		BUILD_SOURCEVERSION=${SOURCE_COMMIT_HASH}
MAKE_ENV+=		VSCODE_QUALITY=stable
MAKE_ENV+=		NODE_OPTIONS="--max-old-space-size=8192"
MAKE_ENV+=		PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=1
MAKE_ENV+=		PYTHONDONTWRITEBYTECODE=1
MAKE_ENV+=		JOBS=${_MAKE_JOBS_N}

CFLAGS+=		-I${PREFIX}/include/node
CXXFLAGS+=		-std=c++20

ELECTRON_URL=		https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
RUN_URL_HASH=		sha256 -s ${ELECTRON_URL} | cut -d' ' -f4
ELECTRON_URL_HASH=	${RUN_URL_HASH:sh}
ELECTRON_ARCH=		${MACHINE_ARCH:S/aarch64/arm64/:S/x86_64/x64/}
ELECTRON_ZIP=		electron-v${ELECTRON_VER}-linux-${ELECTRON_ARCH}.zip
RUN_ZIP_HASH=		sha256 -q ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}/${ELECTRON_ZIP}
RUN_NODEJS_VER=		node --version
NODEJS_VER=		${RUN_NODEJS_VER:sh:C/v//}
COPILOT_DIR=		${WRKSRC}/extensions/copilot/node_modules/@github/copilot-${LOWER_OPSYS}-${ELECTRON_ARCH}
COPILOT_SDK_DIR=	${WRKSRC}/node_modules/@github/copilot-sdk-linux-${ELECTRON_ARCH}
OS_PROXY_RESOLV_DIR_L=	node_modules/@vscode/os-proxy-resolver-linux-${ELECTRON_ARCH}-gnu
OS_PROXY_RESOLV_DIR=	node_modules/@vscode/os-proxy-resolver-pkgsrc-${ELECTRON_ARCH}
RIPGREP_PATHES=		node_modules/@vscode/ripgrep/bin
RIPGREP_PATHES+=	node_modules/@vscode/ripgrep-universal/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
RIPGREP_PATHES+=	build/node_modules/@vscode/ripgrep-universal/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
RIPGREP_PATHES+=	remote/node_modules/@vscode/ripgrep-universal/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
RIPGREP_PATHES+=	${OS_PROXY_RESOLV_DIR}/ripgrep/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
NPM_FLAGS=		--offline --ignore-scripts --no-audit --no-fund --no-update-notifier
NPM_FLAGS+=		--cache ${WRKDIR}/vscode-node_modules-${PKGVERSION_NOREV}

NOT_PAX_MPROTECT_SAFE+=	lib/vscode/code-oss

post-extract:
	# Install scripts
	${CP} ${FILESDIR}/code.sh.in ${WRKSRC}/code-oss.sh
	${CP} ${FILESDIR}/npm-wrapper.sh.in ${WRKSRC}/npm-wrapper.sh
	${CHMOD} +x ${WRKSRC}/npm-wrapper.sh

	# Copy node modules to source tree
	cd ${WRKDIR}/vscode-node_modules-${PKGVERSION_NOREV} && \
		${FIND} . -type f -name "*.tgz" -print | pax -rw -pmp ${WRKSRC}

	# Install node modules from the cache tarball
	cd ${WRKSRC} && ${PATCH} < ${PATCHDIR}/extra-patch-node_ovsx_sign
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install ${NPM_FLAGS}
	for d in `node --input-type=module -e \
	    "console.log(JSON.stringify((await import('${WRKSRC}/build/npm/dirs.ts')).dirs))" \
	    | jq -r '.[]'`; do \
		(cd ${WRKSRC}/$${d} && ${SETENV} ${MAKE_ENV} npm install ${NPM_FLAGS}) || exit 1; \
	done

	# Create moduleignore file
	${CP} ${WRKSRC}/build/.moduleignore.linux \
		${WRKSRC}/build/.moduleignore.${LOWER_OPSYS}

	# Copy electron.d.ts
	${MKDIR} ${WRKSRC}/.build/typings && \
		${CP} ${PREFIX}/lib/${ELECTRON}/gen/electron/tsc/typings/electron.d.ts \
		${WRKSRC}/.build/typings

	# Extract copilot: doesn't work on BSDs, but need for build
	${MKDIR} ${COPILOT_DIR} && cd ${WRKSRC} && \
		${TAR} -xzf copilot-linux-${ELECTRON_ARCH}-*.tgz \
		--strip-components 1 -C ${COPILOT_DIR}
	${MKDIR} ${COPILOT_SDK_DIR} && cd ${WRKSRC} && \
		${TAR} -xzf copilot-sdk-linux-${ELECTRON_ARCH}-*.tgz \
		--strip-components 1 -C ${COPILOT_SDK_DIR}

	# Extract os-proxy-resolver
	cd ${WRKSRC} && ${MKDIR} ${OS_PROXY_RESOLV_DIR} && \
		${TAR} -xzf os-proxy-resolver-linux-${ELECTRON_ARCH}-gnu-*.tgz \
		--strip-components 1 -C ${OS_PROXY_RESOLV_DIR}
	cd ${WRKSRC} && ${MKDIR} ${OS_PROXY_RESOLV_DIR_L} && \
		${TAR} -xzf os-proxy-resolver-linux-${ELECTRON_ARCH}-gnu-*.tgz \
		--strip-components 1 -C ${OS_PROXY_RESOLV_DIR_L}

do-configure:
	# vscode wants a zipped electron
	${MKDIR} ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}
	cd ${PREFIX}/lib/electron${ELECTRON_MAJOR} && \
		zip -q -r ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}/${ELECTRON_ZIP} .
	cd ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH} && \
		${ECHO} "${RUN_ZIP_HASH:sh} *${ELECTRON_ZIP}" > ${WRKSRC}/build/checksums/electron.txt

	# Set electron version
	${SED} -i'' "s|^target=.*|target=\"${ELECTRON_VER}\"|" ${WRKSRC}/.npmrc
	${SED} -i'' "s|^target=.*|target=\"${NODEJS_VER}\"|" ${WRKSRC}/remote/.npmrc

	# Own npm wrapper for working npm pack without network
	${CP} ${WRKSRC}/npm-wrapper.sh ${TOOLS_DIR}/bin/npm

	# Copy rg binary to vscode pathes
.for rgpath in ${RIPGREP_PATHES}
	cd ${WRKSRC} && ${MKDIR} ${rgpath} && ${CP} ${PREFIX}/bin/rg ${rgpath}
.endfor

do-build: do-cargo-build
	# Prepare native node module for os-proxy-resolver
	${CP} ${WRKSRC}/os-proxy-resolver/npm/native/target/release/libos_proxy_resolver_node.so \
		${WRKSRC}/${OS_PROXY_RESOLV_DIR}/os_proxy_resolver.node

	# Build node modules
	for subdir in `${FIND} ${WRKSRC} -type f -path '*/node_modules/*' -name binding.gyp -exec ${DIRNAME} {} ';'`; do \
		if [ "`${ECHO} $${subdir} | ${GREP} /build/node_modules/`" ]; then \
			npm_env="npm_config_runtime=node \
				npm_config_target=${NODEJS_VER} \
				npm_config_nodedir=${PREFIX}" \
			_npmrc="${WRKSRC}/build/.npmrc"; \
		elif [ "`${ECHO} $${subdir} | ${GREP} /remote/node_modules/`" ]; then \
			npm_env="npm_config_runtime=node \
				npm_config_target=${NODEJS_VER} \
				npm_config_nodedir=${PREFIX}" \
			_npmrc="${WRKSRC}/remote/.npmrc"; \
		else \
			npm_env="npm_config_runtime=electron \
				npm_config_target=${ELECTRON_VER} \
				npm_config_nodedir=${PREFIX}/lib/electron${ELECTRON_MAJOR}/node_headers" \
			_npmrc="${WRKSRC}/.npmrc"; \
		fi; \
		cd $${subdir} && \
		if [ -f buildcheck.js ]; then \
			${SETENV} ${MAKE_ENV} $${npm_env} \
				node buildcheck.js > buildcheck.gypi || exit 1; \
		fi && \
		${SETENV} ${MAKE_ENV} $${npm_env} \
			${NODE_GYP} --userconfig=$${_npmrc} rebuild -j ${_MAKE_JOBS_N} || exit 1; \
	done

	# Build vscode
	cd ${WRKSRC} && \
		npm_env="npm_config_runtime=electron \
			npm_config_target=${ELECTRON_VER} \
			npm_config_nodedir=${PREFIX}/lib/electron${ELECTRON_MAJOR}/node_headers" && \
	${SETENV} ${MAKE_ENV} $${npm_env} \
		npm --userconfig=${WRKSRC}/.npmrc run compile && \
	${SETENV} ${MAKE_ENV} $${npm_env} \
		npm --userconfig=${WRKSRC}/.npmrc run gulp vscode-linux-${ELECTRON_ARCH}-min
	${SED} -i'' "s|^#![[:space:]]*${REPLACE.sys-bash.old}|${REPLACE.sys-bash.new}|" \
		${BUILDDIR}/resources/app/extensions/ms-vscode.js-debug/src/targets/node/terminateProcess.sh

BUILDDIR=		${WRKDIR}/VSCode-linux-${ELECTRON_ARCH}
INSTALLATION_DIRS+=	lib/vscode
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/code-oss.sh ${DESTDIR}${PREFIX}/bin/code-oss
	cd ${BUILDDIR} && \
		${FIND} . -type f -print | pax -rw -pmp ${DESTDIR}${PREFIX}/lib/vscode
	${FIND} ${DESTDIR}${PREFIX}/lib/vscode/resources/app/extensions/ms-vscode* -type f -perm -g=w -exec chmod g-w {} +

	# Cleaning
	${FIND} ${DESTDIR}${PREFIX}/lib/vscode -type f \( -name '*.orig' -o -name '*.map' \) -delete
	${RM} -r ${DESTDIR}${PREFIX}/lib/vscode/bin
	${RM} -r ${DESTDIR}${PREFIX}/lib/vscode/gen
	${RM} -r ${DESTDIR}${PREFIX}/lib/vscode/node_headers
	${RM} -r ${DESTDIR}${PREFIX}/lib/vscode/resources/completions

	${INSTALL_DATA} ${WRKSRC}/resources/linux/code.appdata.xml \
		${DESTDIR}${PREFIX}/share/appdata/code-oss.appdata.xml
	${INSTALL_DATA} ${WRKSRC}/resources/linux/code.desktop \
		${DESTDIR}${PREFIX}/share/applications/code-oss.desktop
	${INSTALL_DATA} ${WRKSRC}/resources/linux/code-url-handler.desktop \
		${DESTDIR}${PREFIX}/share/applications/code-oss-url-handler.desktop
	${INSTALL_DATA} ${BUILDDIR}/resources/app/resources/linux/code.png \
		${DESTDIR}${PREFIX}/share/pixmaps/com.visualstudio.code.oss.png
	${INSTALL_DATA} ${WRKSRC}/resources/completions/bash/code \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/code-oss
	${INSTALL_DATA} ${WRKSRC}/resources/completions/zsh/_code \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_code-oss

.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/nodejs/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
