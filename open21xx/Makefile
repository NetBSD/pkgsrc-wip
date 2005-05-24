# $NetBSD: Makefile,v 1.3 2005/05/24 10:31:14 rillig Exp $
#

DISTNAME=		open21xx0.7.2
PKGNAME=		open21xx-0.7.2
CATEGORIES=		lang
MASTER_SITES=	http://www3.telus.net/sharpshin/downloads/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www3.telus.net/sharpshin/adi.html
COMMENT=		Assembler tool suite for the Analog Devices 21xx family of DSP

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
USE_GNU_TOOLS+= yacc

.include "../../devel/flex/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
