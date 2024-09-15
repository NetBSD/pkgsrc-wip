# $NetBSD$

GITHUB_TAG=	20925bb
DISTNAME=	OpenSTA-${GITHUB_TAG}
PKGNAME=	OpenSTA-2.6.0.1628
CATEGORIES=	cad devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=The-OpenROAD-Project/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/The-OpenROAD-Project/OpenSTA/
COMMENT=	Gate level static timing verifier
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/OpenSTA-20925bb00965c1199c45aca0318c2baeb4042c5a

GCC_REQD+=	13
FORCE_CXX_STD=	c++20

USE_LANGUAGES=	c++
USE_TOOLS+=	chmod cp bison find pax

INSTALLDIRS=	etc tcl spice dcalc liberty parasitics power sdf graph network sdf search util sdc
SHAREDIR=	${DESTDIR}${PREFIX}/share/sta
INCLUDEDIR=	${DESTDIR}${PREFIX}/include/sta

post-install:
.for idir in ${INSTALLDIRS}
	cd ${WRKSRC} && ${FIND} ${idir} -name \*.hh -exec ${PAX} -rw {} ${INCLUDEDIR} \;
	cd ${WRKSRC} && ${FIND} ${idir} -name \*.tcl -exec ${PAX} -rw {} ${SHAREDIR} \;
	cd ${WRKSRC} && ${FIND} ${idir} -name \*.i -exec ${PAX} -rw {} ${SHAREDIR} \;
.endfor


.include "../../math/eigen3/buildlink3.mk"
.include "../../devel/swig3/buildlink3.mk"
.include "../../wip/cudd/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
