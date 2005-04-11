# $NetBSD: Makefile,v 1.7 2005/04/11 21:13:58 tvierling Exp $
#

DISTNAME=	matchbox-common-0.9.1
CATEGORIES=	wm
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-common/0.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Pixmaps for Matchbox

USE_X11=	yes
GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	matchbox

SUBST_CLASSES+=		session
SUBST_MESSAGE.session=	"Fixing location of system-wide matchbox session."
SUBST_STAGE.session=	pre-configure
SUBST_FILES.session=	matchbox-session
SUBST_SED.session=	-e 's|/etc/matchbox|${PKG_SYSCONFDIR}|g'

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
