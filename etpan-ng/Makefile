# $NetBSD: Makefile,v 1.6 2004/12/30 02:17:00 dawszy Exp $
#

DISTNAME=		etpan-ng-0.5
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://libetpan.sourceforge.net/etpan/
COMMENT=		Mail console client with S/MIME, PGP and bogofilter support

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mail/libetpan/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
