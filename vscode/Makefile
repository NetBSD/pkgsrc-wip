# $NetBSD: $

DISTNAME=		vscode-1.147.0
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=microsoft/}
GITHUB_TAG=		${PKGVERSION_NOREV}
SOURCE_COMMIT_HASH=	69047191fc427f2f92828279aae1d90d8eeda7ab

NODE_MODULES=		vscode-node_modules-${PKGVERSION_NOREV}.tar.gz
MASTER_SITES+=		https://distfiles.borderland.hu/
DISTFILES+=		${NODE_MODULES}
DISTFILES+=		${DEFAULT_DISTFILES}

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://code.visualstudio.com/
COMMENT=		The Open Source build of Visual Studio Code (vscode) editor
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		zip gmake pkg-config pax bash

USE_CXX_FEATURES+=	c++20

TOOL_DEPENDS+=		jq-[0-9]*:../../devel/jq
TOOL_DEPENDS+=		typescript-[0-9]*:../../lang/typescript
TOOL_DEPENDS+=		ripgrep-[0-9]*:../../textproc/ripgrep
TOOL_DEPENDS+=		wabt-[0-9]*:../../wip/wabt

.include "../../wip/electron43/electron.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_MESSAGE.vars=	Fixing variables
SUBST_FILES.vars+=	node_modules/.pnpm/typescript@7.1.0-dev.20261105.1/node_modules/typescript/lib/getExePath.js
SUBST_FILES.vars+=	src/vs/platform/native/electron-main/nativeHostMainService.ts
SUBST_FILES.vars+=	code-oss.sh
SUBST_VARS.vars+=	PREFIX

SUBST_CLASSES+=		npm
SUBST_STAGE.npm=	pre-configure
SUBST_MESSAGE.npm=	Prepare npm wrapper script
SUBST_FILES.npm+=	npm-wrapper.sh
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
REPLACE_NODEJS+=	extensions/copilot/node_modules/@github/copilot/npm-loader.js
REPLACE_NODEJS+=	extensions/copilot/node_modules/markdown-it/bin/markdown-it.mjs
REPLACE_NODEJS+=	extensions/node_modules/typescript/bin/tsc
REPLACE_NODEJS+=	extensions/node_modules/typescript/bin/tsserver
REPLACE_NODEJS+=	node_modules/@devcontainers/cli/devcontainer.js
REPLACE_NODEJS+=	node_modules/@vscode/sandbox-runtime/dist/cli.js
REPLACE_NODEJS+=	node_modules/@vscode/vscode-languagedetection/cli/index.js
REPLACE_NODEJS+=	node_modules/chrome-remote-interface/bin/client.js

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
RIPGREP_PATHES=		node_modules/@vscode/ripgrep/bin
RIPGREP_PATHES+=	node_modules/@vscode/ripgrep-universal/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
RIPGREP_PATHES+=	build/node_modules/@vscode/ripgrep-universal/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
RIPGREP_PATHES+=	remote/node_modules/@vscode/ripgrep-universal/bin/${LOWER_OPSYS}-${ELECTRON_ARCH}
PNPM_ROOTS=		. build remote
PNPM_ENV=		pnpm_config_store_dir=${WRKDIR}/vscode-node_modules-${PKGVERSION_NOREV}/store
PNPM_ENV+=		pnpm_config_minimum_release_age=0 pnpm_config_pm_on_fail=ignore

NOT_PAX_MPROTECT_SAFE+=	lib/vscode/code-oss

.if defined(VSCODE_MAINTAINER)
.  if make(cache-tarball)
DISTFILES=		${DEFAULT_DISTFILES}
.  endif

# For create pnpm store tarball
USE_TOOLS+=		bsdtar

MPNPM_FLAGS=		--pm-on-fail=ignore --ignore-scripts
MPNPM_FLAGS+=		--store-dir=${WRKDIR}/vscode-tmp/vscode-node_modules-${PKGVERSION_NOREV}/store
MPNPM_OVERLAY=		package.json pnpm-lock.yaml
MPNPM_OVERLAY+=		remote/package.json remote/pnpm-lock.yaml

.PHONY: cache-tarball
cache-tarball: makesum
	${MKDIR} ${WRKDIR}/vscode-tmp/vscode-node_modules-${PKGVERSION_NOREV}/store \
		${WRKDIR}/vscode-tmp/vscode-node_modules-${PKGVERSION_NOREV}/overlay/remote
	${TOOLS_PATH.bsdtar} -zxf ${DISTDIR}/${DISTNAME}.tar.gz \
		--strip-components=1 -C ${WRKDIR}/vscode-tmp
	# node-ovsx-sign
	cd ${WRKDIR}/vscode-tmp && pnpm ${MPNPM_FLAGS} add \
		--save-prod --lockfile-only --workspace-root node-ovsx-sign
	cd ${WRKDIR}/vscode-tmp/remote && pnpm ${MPNPM_FLAGS} add \
		--save-prod --lockfile-only node-ovsx-sign
.  for f in ${MPNPM_OVERLAY}
	${CP} ${WRKDIR}/vscode-tmp/${f} \
		${WRKDIR}/vscode-tmp/vscode-node_modules-${PKGVERSION_NOREV}/overlay/${f}
.  endfor
.  for r in ${PNPM_ROOTS}
	cd ${WRKDIR}/vscode-tmp/${r} && \
		printf 'supportedArchitectures:\n  os: [current]\n  cpu: [current]\n' \
		>> pnpm-workspace.yaml && \
		pnpm ${MPNPM_FLAGS} fetch
.  endfor

	cd ${WRKDIR}/vscode-tmp && \
		${TOOLS_PATH.bsdtar} -czf ${WRKDIR}/vscode-node_modules-${PKGVERSION_NOREV}.tar.gz \
			vscode-node_modules-${PKGVERSION_NOREV}
.endif

post-extract:
	# Install scripts
	${CP} ${FILESDIR}/code.sh.in ${WRKSRC}/code-oss.sh
	${CP} ${FILESDIR}/npm-wrapper.sh.in ${WRKSRC}/npm-wrapper.sh
	${CHMOD} +x ${WRKSRC}/npm-wrapper.sh

	# Create moduleignore file
	${CP} ${WRKSRC}/build/.moduleignore.linux \
		${WRKSRC}/build/.moduleignore.${LOWER_OPSYS}

	# Install node modules from the cache tarball
	cd ${WRKDIR}/vscode-node_modules-${PKGVERSION_NOREV}/overlay && \
		pax -rw -pmp . ${WRKSRC}
.for r in ${PNPM_ROOTS} extensions extensions/copilot
	cd ${WRKSRC}/${r} && ${SETENV} ${MAKE_ENV} ${PNPM_ENV} \
		pnpm install --offline --frozen-lockfile --ignore-scripts
.endfor

	# Copy electron.d.ts
	${MKDIR} ${WRKSRC}/.build/typings && \
		${CP} ${PREFIX}/lib/${ELECTRON}/gen/electron/tsc/typings/electron.d.ts \
		${WRKSRC}/.build/typings

post-patch:
	# Set electron and nodejs versions
	cd ${WRKSRC} && \
		jq '.nativeBuild.target="${ELECTRON_VER}"' package.json > package.json.jq && \
		${MV} package.json.jq package.json
	cd ${WRKSRC}/remote && \
		jq '.nativeBuild.target="${NODEJS_VER}"' package.json > package.json.jq && \
		${MV} package.json.jq package.json
	cd ${WRKSRC}/extensions/copilot && ${SETENV} ${MAKE_ENV} ${PNPM_ENV} \
		pnpm run postinstall

do-configure:
	# vscode wants a zipped electron
	${MKDIR} ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}
	cd ${PREFIX}/lib/electron${ELECTRON_MAJOR} && \
		zip -q -r ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH}/${ELECTRON_ZIP} .
	cd ${WRKDIR}/.home/.cache/electron/${ELECTRON_URL_HASH} && \
		${ECHO} "${RUN_ZIP_HASH:sh} *${ELECTRON_ZIP}" > ${WRKSRC}/build/checksums/electron.txt

	# Own npm wrapper for working npm pack without network
	${CP} ${WRKSRC}/npm-wrapper.sh ${TOOLS_DIR}/bin/npm

	# Copy rg binary to vscode pathes
.for rgpath in ${RIPGREP_PATHES}
	cd ${WRKSRC} && ${MKDIR} ${rgpath} && ${CP} ${PREFIX}/bin/rg ${rgpath}
.endfor

do-build:
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
		pnpmenv="pnpm_config_runtime=electron \
			pnpm_config_target=${ELECTRON_VER} \
			pnpm_config_nodedir=${PREFIX}/lib/electron${ELECTRON_MAJOR}/node_headers" && \
	${SETENV} ${MAKE_ENV} $${pnpmenv} ${PNPM_ENV} \
		pnpm run compile && \
	${SETENV} ${MAKE_ENV} $${pnpmenv} ${PNPM_ENV} \
		pnpm run gulp vscode-linux-${ELECTRON_ARCH}-min
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
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
