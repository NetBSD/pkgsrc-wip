# $NetBSD: Makefile,v 1.1.1.1 2004/08/13 08:03:07 ianzag Exp $
#

DISTNAME=		open21xx0.7.2
PKGNAME=		open21xx-0.7.2
CATEGORIES=		lang
MASTER_SITES=	http://www3.telus.net/sharpshin/downloads/

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www3.telus.net/sharpshin/adi.html
COMMENT=		Assembler tool suite for the Analog Devices 21xx family of DSP

USE_BUILDLINK3=	YES
USE_LANGUAGES=	c
USE_GNU_TOOLS+=	make
USE_GNU_TOOLS+= yacc

.include "../../devel/flex/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
