# $NetBSD: Makefile,v 1.6 2005/05/24 10:30:29 rillig Exp $
#

DISTNAME=		ksambaplugin-0.5
CATEGORIES=		kde net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ksambakdeplugin/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://ksambakdeplugin.sourceforge.net/
COMMENT=		KSambaPlugin is a KDE 3 plugin for configuring a SAMBA server

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
