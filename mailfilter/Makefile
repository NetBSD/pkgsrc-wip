# $NetBSD: Makefile,v 1.2 2003/09/28 03:38:59 virtus Exp $
#

DISTNAME=	mailfilter-0.2.4
WRKSRC=		${WRKDIR}/*
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailfilter/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://mailfilter.sourceforge.net/
COMMENT=	Filter mail on a pop3 server

USE_BUILDLINK2=	YES
GNU_CONFIGURE=  YES

USE_PKGLOCALEDIR=YES

.include "../../mk/bsd.pkg.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
