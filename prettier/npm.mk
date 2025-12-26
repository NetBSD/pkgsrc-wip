# $NetBSD$

INSTALL_DIRS?=	.

USE_TOOLS+=	pax

NODE_MODULES_NAME?=	${PKGBASE}

SUBST_CLASSES+=		node
SUBST_SED.node+=	-e 's,\#!.*node,\#!'"${PREFIX}/bin/node,"
SUBST_STAGE.node=	post-build
SUBST_MESSAGE.node=	Fixing path to node binary.
SUBST_FILES.node+=	${REPLACE_NODE}

post-extract:
	if ${TEST} -f ${FILESDIR}/npm-shrinkwrap.json; then \
		if ${TEST} -f ${WRKSRC}/npm-shrinkwrap.json; then \
			${ECHO} npm-shrinkwrap.json exists in both ${FILESDIR} and ${WRKSRC}, remove it from ${FILESDIR}; \
			exit 1; \
		fi; \
		${CP} ${FILESDIR}/npm-shrinkwrap.json ${WRKSRC}; \
	fi

# install dependencies from the cache
do-build:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} npm config set cache=${WRKDIR}/npmcache
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} npm ci --no-audit --no-fund

# install the project into ${DESTDIR}
# but this uses symlinks, so replace symlink with files
do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} npm install -g --no-fund .
	${RM} ${DESTDIR}${PREFIX}/lib/node_modules/${NODE_MODULES_NAME}
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} pax -pp -rw * ${DESTDIR}${PREFIX}/lib/node_modules/${NODE_MODULES_NAME}

# update target needs network to download new files
.if make(update-cache)
ALLOW_NETWORK_ACCESS=	yes
.endif

.PHONY: update-cache
update-cache: do-extract
	${RM} -rf ${WRKDIR}/npmcache
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm config set cache=${WRKDIR}/npmcache
# use node-shrinkwrap.json to wire down dependencies
# make one if it doesn't exist, but prefer upstream package-lock.json to re-creating it
# directly calling 'npm shrinkwrap' makes bigger files, but doesn't include all dependencies
	if ${TEST} ! -f  ${WRKSRC}/npm-shrinkwrap.json; then \
		if ${TEST} ! -f ${WRKSRC}/package-lock.json; then \
			cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --package-lock-only; \
		fi; \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm shrinkwrap; \
		${CP} ${WRKSRC}/npm-shrinkwrap.json ${FILESDIR}; \
	fi
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --no-fund --no-audit
	cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} tar -czf ${DISTNAME}-dependencies.tar.gz npmcache/_cacache
	${ECHO} new tarball in ${WRKDIR}/${DISTNAME}-dependencies.tar.gz - please check it and moved it to ${DISTDIR}
	${ECHO} then add it to DISTFILES and re-generate the distinfo file

_VARGROUPS+=	npm

# install a nodejs package to provide the npm binary
.include "../../lang/nodejs/nodeversion.mk"
