# $NetBSD: Makefile,v 1.6 2005/01/23 21:39:30 marc Exp $

DISTNAME=       superkaramba-0.33
CATEGORIES=     x11 misc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=netdragon/}

MAINTAINER=     dotz@irc.pl
HOMEPAGE=       http://netdragon.sourceforge.net/
COMMENT=        Interactive eyecandy for your KDE desktop

USE_GNU_TOOLS+=	make
USE_BUILDLINK3= YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-pythondir=${PREFIX}
USE_LIBTOOL=	yes

PYTHON_VERSIONS_ACCEPTED=	23

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
