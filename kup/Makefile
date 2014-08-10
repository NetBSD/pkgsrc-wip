# $NetBSD: Makefile,v 1.1 2014/08/10 11:21:07 thomasklausner Exp $

DISTNAME=	147465-kup-0.4.2
PKGNAME=	${DISTNAME:C/.*-kup/kup/}
CATEGORIES=	sysutils
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kde-apps.org/content/show.php/Kup+Backup+System?content=147465
COMMENT=	KDE frontend for bup and rsync
LICENSE=	gnu-gpl-v2

DEPENDS+=	bup-[0-9]*:../../sysutils/bup
DEPENDS+=	rsync-[0-9]*:../../net/rsync

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
