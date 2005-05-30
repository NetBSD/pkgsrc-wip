# $NetBSD: Makefile,v 1.3 2005/05/30 16:55:26 leonardschmidt Exp $
#

DISTNAME=	wmii-0-20050529
PKGNAME=	wmii-20050529
CATEGORIES=	wm x11
MASTER_SITES=	http://wmi.modprobe.de/snaps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wmi.modprobe.de/
COMMENT=	Modular, minimalist and highly customizable window manager

USE_PKGINSTALL=	yes
USE_X11=	yes
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/wmii-0-20050529

SUBST_CLASSES+=	paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	rc/rc
SUBST_SED.paths=	-e 's,CONFPREFIX/wmii,${PKG_SYSCONFDIR},'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Solaris"
CFLAGS+=	-D__EXTENSIONS__
.endif

PKG_SYSCONFSUBDIR=	wmii

EGDIR=		${PREFIX}/share/examples/wmii
CONF_FILES=
.for f in actions bar input keys rc rc.conf status.sh wmii
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

.include "../../mk/bsd.pkg.mk"
