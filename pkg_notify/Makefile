# $NetBSD: Makefile,v 1.5 2004/11/08 11:49:31 imilh Exp $
#

DISTNAME=	pkg_notify-0.2
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/
COMMENT=	Notifies package maintainer when a new version is available

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww

WRKSRC=		${WRKDIR}/pkg_notify

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_PERL5=	yes

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=	pkg_notify
SUBST_MESSAGE.pkg_notify=	"Setting up various path."
SUBST_STAGE.pkg_notify=		post-patch
SUBST_FILES.pkg_notify=		pkg_notify
SUBST_SED.pkg_notify=		-e 's|@PKGSRCDIR@|${PKGSRCDIR}|'	\
				-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
				-e 's|@MAKE@|${MAKE}|g'			\
				-e 's|@PERL@|${PERL5}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
