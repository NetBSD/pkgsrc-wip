# $NetBSD: Makefile,v 1.5 2005/01/01 22:27:12 mattd Exp $
#

DISTNAME=	matchbox-common-0.8
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.handhelds.org/projects/matchbox/sources/matchbox-common/0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Pixmaps for Matchbox

USE_BUILDLINK3=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	matchbox

SUBST_CLASSES+=		session
SUBST_MESSAGE.session=	"Fixing location of system-wide matchbox session."
SUBST_STAGE.session=	pre-configure
SUBST_FILES.session=	matchbox-session
SUBST_SED.session=	-e 's|/etc/matchbox|${PKG_SYSCONFDIR}|g'

.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
