# $NetBSD: Makefile,v 1.2 2003/12/13 12:24:52 johnrshannon Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-c++-${GCC_VERSION}-devel
COMMENT=		GNU Compiler Collection, version 3-${SNAPDATE}, c++ compiler

.include "../gcc3-c-devel/buildaddon.mk"

CONFIGURE_ARGS+=	--enable-languages="c++"
CONFIGURE_ARGS+=	--disable-nls

post-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} configure-host)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} configure-target)

do-build:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} c++)
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} g++)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} maybe-all-target-libstdc++-v3)

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

do-test:
	(cd ${WRKSRC}/gcc && && ${SETENV} ${MAKE_ENV} ${GMAKE} check-c++)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1plus ${GCC_ARCHDIR}
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		c++.install-common c++.install-man)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libstdc++-v3)

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/c++.mk

.include "../../mk/bsd.pkg.mk"
