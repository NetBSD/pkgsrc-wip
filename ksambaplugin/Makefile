# $NetBSD: Makefile,v 1.1.1.1 2004/06/24 15:10:11 ianzag Exp $
#

DISTNAME=		ksambaplugin-0.5
CATEGORIES=		kde net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ksambakdeplugin/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://ksambakdeplugin.sourceforge.net/
COMMENT=		KSambaPlugin is a KDE 3 plugin for configuring a SAMBA server

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
