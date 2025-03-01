# $NetBSD: Makefile,v 1.40 2023/12/23 01:59:43 zafer Exp $
#

DISTNAME=	tkgate-2.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=bnoordhuis/}
GITHUB_TAG=	856c40542d3ee5ab0c23cb86a2a4ca0ba623619f

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tkgate.org/
COMMENT=	Tcl/Tk based digital circuit editor and simulator
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv

#SE_IMAKE=		yes
USE_TOOLS+=		gm4 bison autoconf pkg-config

TKGATE_SITENAME=	Earth

CONFIGURE_ENV+=		BUILDLINK_LDFLAGS=${BUILDLINK_LDFLAGS:Q}
CONFIGURE_ENV+=		LOCALBASE=${PREFIX}
#ONFIGURE_ENV+=		DESTDIR=${DESTDIR}

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths to find tclConfig.sh, man page
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure.ac acinclude.m4
SUBST_VARS.prefix=	PREFIX

#KGCONFIG_OVERRIDE+=	tcl.pc.in

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

do-configure:
	${ECHO} "${TKGATE_SITENAME}" > ${WRKSRC}/sitename.txt
	( cd ${WRKSRC} && ${CONFIGURE_ENV} ./configure )

.include "../../x11/tk/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
