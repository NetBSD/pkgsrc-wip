# $NetBSD: Makefile,v 1.15 2010/01/18 09:38:26 thomasklausner Exp $
#

DISTNAME=	kxmleditor-1.0.0
PKGREVISION=	4
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kxmleditor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kxmleditor.sourceforge.net/
COMMENT=	KDE xml editor

WRKSRC=			${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_LIBTOOL=		yes
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
