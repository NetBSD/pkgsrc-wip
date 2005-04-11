# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:57 tvierling Exp $
#

DISTNAME=	mailfilter-0.2.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailfilter/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://mailfilter.sourceforge.net/
COMMENT=	Filter mail on a pop3 server

GNU_CONFIGURE=  YES
WRKSRC=		${WRKDIR}/*

USE_PKGLOCALEDIR=YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
