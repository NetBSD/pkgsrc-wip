# $NetBSD: Makefile,v 1.1.1.1 2003/04/05 16:14:37 virtus Exp $
#

DISTNAME=	mailfilter-0.2.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailfilter/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://mailfilter.sourceforge.net
COMMENT=	Filter mail on a pop3 server

WRKSRC=		${WRKDIR}/*
USE_BUILDLINK2=	YES
GNU_CONFIGURE=  YES

USE_PKGLOCALEDIR=YES

.include "../../mk/bsd.pkg.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
