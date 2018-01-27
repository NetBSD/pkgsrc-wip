# $NetBSD: Makefile,v 1.3 2012/09/29 16:46:13 asau Exp $

H_VERSION=	0.2.5
DISTNAME=	habak-${H_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.gna.org/fvwm-crystal/habak/${H_VERSION}/

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://fvwm-crystal.org/
COMMENT=	Layered desktop background tool

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/habak-${H_VERSION}/src

SUBST_CLASSES+=			fix-linking
SUBST_STAGE.fix-linking=	pre-build
SUBST_MESSAGE.fix-linking=	Fixing linking.
SUBST_FILES.fix-linking=	Makefile
SUBST_SED.fix-linking=		-e 's,CFLAGS += -I/usr/X11R6/include -Wall,,g'
SUBST_SED.fix-linking+=		-e 's,LDFLAGS += -L/usr/X11R6/lib -lImlib2 -lm,LDFLAGS += -lImlib2 -lm,g'


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/habak ${DESTDIR}${PREFIX}/bin


.include "../../graphics/imlib2/buildlink3.mk"
#.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
