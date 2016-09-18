# $NetBSD: Makefile,v 1.8 2012/10/07 20:11:07 asau Exp $

DISTNAME=		wings-1.5.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wings/}
EXTRACT_SUFX=		.tar.bz2

MAINTAIER=		ghen@NetBSD.org
HOMEPAGE=		http://www.wings3d.com/
COMMENT=		3D modeling program with a friendly interface


USE_TOOLS+=		gmake

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	unix/install_wings.src
SUBST_SED.paths=	-e 's,%%LOCALBASE%%,${LOCALBASE},'

ESDL_VERSION=		0.95.0630
ESDL_PATH=		${LOCALBASE}/lib/erlang/lib/esdl-${ESDL_VERSION}

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	tools/wings_reduce_otp

post-build:
	cd ${WRKSRC} && ${SETENV} ESDL_PATH=${ESDL_PATH} unix/make_installer

do-install:
	cd ${WRKSRC}/wings-0.98.29b-netbsd && ${SH} install_wings
	${INSTALL} -lsr ${LOCALBASE}/lib/erlang/lib/${PKGNAME}/wings ${LOCALBASE}/bin

.include "../../lang/erlang/buildlink3.mk"
BUILDLINK_API_DEPENDS.erlang+=	erlang>=10
.include "../../wip/esdl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
#.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
