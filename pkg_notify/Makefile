# $NetBSD: Makefile,v 1.3 2004/10/27 13:36:34 xtraeme Exp $
#

DISTNAME=	pkg_notify-0.1
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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_notify ${PREFIX}/bin

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-extract
SUBST_FILES.path=	pkg_notify
SUBST_SED.path=		-e "s|/usr/pkgsrc|${PKGSRCDIR}|g" \
			-e "s|/usr/pkg|${LOCALBASE}|g"
SUBST_MESSAGE.path=	"Fixing harcoded paths."

.include "../../mk/bsd.pkg.mk"
