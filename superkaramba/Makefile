# $NetBSD: Makefile,v 1.3 2004/01/25 02:33:42 grantbeattie Exp $

DISTNAME=       superkaramba-0.33
CATEGORIES=     x11 misc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=netdragon/}

MAINTAINER=     dotz@irc.pl
HOMEPAGE=       http://netdragon.sourceforge.net/
COMMENT=        Interactive eyecandy for your KDE desktop

USE_GNU_TOOLS+=	make
USE_BUILDLINK2= YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-pythondir=${PREFIX}
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PYTHON_VERSIONS_ACCEPTED=	23 23pth

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
