# $NetBSD: Makefile,v 1.2 2003/05/27 11:58:56 xtraeme Exp $
#

DISTNAME=	streamripper-1.32
CATEGORIES=	audio
MASTER_SITES=	http://streamripper.sourceforge.net/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://streamripper.sourceforge.net/
COMMENT=	Splits SHOUTcast stream into tracks

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamripper ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
