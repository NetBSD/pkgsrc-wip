# $NetBSD: Makefile,v 1.1.1.1 2003/09/21 20:16:54 mpasternak Exp $

DISTNAME=       superkaramba-0.32b
CATEGORIES=     x11 misc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=netdragon/}

MAINTAINER=     dotz@irc.pl
HOMEPAGE=       http://netdragon.sourceforge.net/
COMMENT=        Interactive eyecandy for your KDE desktop

USE_BUILDLINK2= YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-pythondir=${PREFIX}

PYTHON_VERSIONS_ACCEPTED=	23 23pth

.include	"../../x11/kdelibs3/buildlink2.mk"
.include	"../../lang/python/extension.mk"
.include	"../../graphics/jpeg/buildlink2.mk"
.include        "../../mk/bsd.pkg.mk"
