# $NetBSD: Makefile,v 1.3 2004/02/02 18:24:28 dawszy Exp $
#

DISTNAME=		etpan-ng-0.3
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		dawszy@arhea.pl
HOMEPAGE=		http://libetpan.sourceforge.net/etpan/
COMMENT=		Mail console client with S/MIME, PGP and bogofilter support

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/libetpan/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
