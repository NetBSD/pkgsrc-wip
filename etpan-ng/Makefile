# $NetBSD: Makefile,v 1.4 2004/04/28 00:13:18 blef Exp $
#

DISTNAME=		etpan-ng-0.3
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://libetpan.sourceforge.net/etpan/
COMMENT=		Mail console client with S/MIME, PGP and bogofilter support

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/libetpan/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
