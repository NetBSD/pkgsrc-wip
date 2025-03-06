# $NetBSD: $

DISTNAME=		vscode-1.97.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=		${PKGVERSION_NOREV}

NODE_MODULES=		vscode-node_modules-${PKGVERSION_NOREV}.tar.gz
#NOTE: SITES.${NODE_MODULES} doesn't work
#SITES.${NODE_MODULES}=	https://downloads.sourceforge.net/sourceforge/kikadf/NetBSD/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=kikadf/NetBSD/}
DISTFILES+=		${NODE_MODULES}
DISTFILES+=		${DEFAULT_DISTFILES}

MAINTAINER=		kikadf.01@gmail.com
HOMEPAGE=		https://code.visualstudio.com/
COMMENT=		The Open Source build of Visual Studio Code (vscode) editor
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		zip gmake pkg-config pax bash

USE_CXX_FEATURES+=	c++17
USE_ELECTRON=		bundled

DEPENDS+=		ripgrep-[0-9]*:../../textproc/ripgrep

.include "../../wip/electron32/platform.mk"

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	src/vs/platform/native/electron-main/nativeHostMainService.ts
SUBST_FILES.path+=	code-oss.sh
SUBST_VARS.path+=	PREFIX

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

REPLACE_NODEJS=		extensions/node_modules/typescript/bin/tsc
REPLACE_NODEJS+=	extensions/node_modules/typescript/bin/tsserver
REPLACE_NODEJS+=	node_modules/@parcel/watcher/node_modules/detect-libc/bin/detect-libc.js
REPLACE_NODEJS+=	node_modules/@vscode/vscode-languagedetection/cli/index.js
REPLACE_NODEJS+=	node_modules/chrome-remote-interface/bin/client.js
REPLACE_NODEJS+=	node_modules/is-docker/cli.js
REPLACE_NODEJS+=	node_modules/mkdirp/bin/cmd.js
REPLACE_NODEJS+=	node_modules/opentype.js/bin/ot
REPLACE_NODEJS+=	node_modules/opentype.js/bin/server.js
REPLACE_NODEJS+=	node_modules/opentype.js/bin/test-render
REPLACE_NODEJS+=	node_modules/rc/cli.js
REPLACE_NODEJS+=	node_modules/uuid/dist/bin/uuid
REPLACE_NODEJS+=	node_modules/semver/bin/semver.js


MAKE_ENV+=		ELECTRON_SKIP_BINARY_DOWNLOAD=1
MAKE_ENV+=		PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=1
MAKE_ENV+=		PYTHONDONTWRITEBYTECODE=1
MAKE_ENV+=		JOBS=${_MAKE_JOBS_N}

CFLAGS+=		-I${PREFIX}/include/node
CXXFLAGS+=		-std=c++17

ELECTRON_URL=		https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
RUN_URL_HASH=		sha256 -s ${ELECTRON_URL} | cut -d' ' -f4
ELECTRON_URL_HASH=	${RUN_URL_HASH:sh}
ELECTRON_ARCH=		${MACHINE_ARCH:S/aarch64/arm64/:S/x86_64/x64/}
ELECTRON_ZIP=		electron-v${ELECTRON_VER}-linux-${ELECTRON_ARCH}.zip
RUN_ZIP_HASH=		sha256 -q ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}/${ELECTRON_ZIP}
RUN_NODEJS_VER=		node --version
NODEJS_VER=		${RUN_NODEJS_VER:sh}

NOT_PAX_MPROTECT_SAFE+=	lib/vscode/code-oss

post-extract:
	# Install script
	${CP} ${FILESDIR}/code.sh.in ${WRKSRC}/code-oss.sh
	# Set electron version
	${SED} -i'' "s|^target=.*|target=\"${ELECTRON_VER}\"|" ${WRKSRC}/.npmrc
	${SED} -i'' "s|^target=.*|target=\"${NODEJS_VER}\"|" ${WRKSRC}/remote/.npmrc
	# Copy node modules to source tree
	cd ${WRKDIR}/vscode-node_modules-${PKGVERSION_NOREV} && \
		${FIND} . -type f -print | pax -rw -pmp ${WRKSRC}
	# Create moduleignore file
	${CP} ${WRKSRC}/build/.moduleignore.linux \
		${WRKSRC}/build/.moduleignore.${LOWER_OPSYS}

do-configure:
	# vscode wants a zipped electron
	${MKDIR} ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}
	cd ${PREFIX}/lib/electron${ELECTRON_MAJOR} && \
		zip -q -r ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}/${ELECTRON_ZIP} .
	cd ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH} && \
		${ECHO} "${RUN_ZIP_HASH:sh} *${ELECTRON_ZIP}" > ${WRKSRC}/build/checksums/electron.txt
	# Build node modules
	for subdir in `${FIND} ${WRKSRC} -type f -name binding.gyp -exec ${DIRNAME} {} ';'`; do \
		if [ "`${ECHO} $${subdir} | ${GREP} /build/node_modules/`" ]; then \
			cd $${subdir} && \
			${SETENV} ${MAKE_ENV} \
				npm_config_runtime=node \
				npm_config_target=${NODEJS_VER} \
				npm_config_nodedir=${PREFIX} \
				${NODE_GYP} --userconfig=${WRKSRC}/build/.npmrc rebuild -j ${_MAKE_JOBS_N} || exit 1; \
		elif [ "`${ECHO} $${subdir} | ${GREP} /remote/node_modules/`" ]; then \
			cd $${subdir} && \
			${SETENV} ${MAKE_ENV} \
				npm_config_runtime=node \
				npm_config_target=${NODEJS_VER} \
				npm_config_nodedir=${PREFIX} \
				${NODE_GYP} --userconfig=${WRKSRC}/remote/.npmrc rebuild -j ${_MAKE_JOBS_N} || exit 1; \
		else \
			cd $${subdir} && \
			${SETENV} ${MAKE_ENV} \
				npm_config_runtime=electron \
				npm_config_target=${ELECTRON_VER} \
				npm_config_nodedir=${PREFIX}/lib/electron${ELECTRON_MAJOR}/node_headers \
				${NODE_GYP} --userconfig=${WRKSRC}/.npmrc rebuild -j ${_MAKE_JOBS_N} || exit 1; \
		fi; \
	done
	# Copy rg binary to @vscode/ripgrep/bin
	${MKDIR} ${WRKSRC}/node_modules/@vscode/ripgrep/bin
	${CP} ${PREFIX}/bin/rg ${WRKSRC}/node_modules/@vscode/ripgrep/bin
	${MKDIR} ${WRKSRC}/build/node_modules/@vscode/ripgrep/bin
	${CP} ${PREFIX}/bin/rg ${WRKSRC}/build/node_modules/@vscode/ripgrep/bin
	${MKDIR} ${WRKSRC}/remote/node_modules/@vscode/ripgrep/bin
	${CP} ${PREFIX}/bin/rg ${WRKSRC}/remote/node_modules/@vscode/ripgrep/bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npx ${WRKSRC}/node_modules/typescript/bin/tsc -p build/tsconfig.build.json
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		npm_config_runtime=electron \
		npm_config_target=${ELECTRON_VER} \
		npm_config_nodedir=${PREFIX}/lib/electron${ELECTRON_MAJOR}/node_headers \
		npm --userconfig=${WRKSRC}/.npmrc run gulp vscode-linux-${ELECTRON_ARCH}-min
	${SED} -i'' "s|^#![[:space:]]*${REPLACE.sys-bash.old}|${REPLACE.sys-bash.new}|" \
		${BUILDDIR}/resources/app/extensions/ms-vscode.js-debug/src/targets/node/terminateProcess.sh
	${FIND} ${BUILDDIR} -type f -name '*.orig' -delete

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
	${LN} -sf ${PREFIX}/bin/rg \
		${DESTDIR}${PREFIX}/lib/vscode/resources/app/node_modules/@vscode/ripgrep/bin/rg
	${FIND} ${DESTDIR}${PREFIX}/lib/vscode/resources/app/extensions/ms-vscode* -type f -perm -g=w -exec chmod g-w {} +
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
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
KRB5_DEFAULT=		mit-krb5
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
