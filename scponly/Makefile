# $NetBSD: Makefile,v 1.4 2004/04/25 06:49:09 blef Exp $
# FreeBSD Id: ports/shells/scponly/Makefile,v 1.1 2002/09/10 22:18:46 obraun Exp

DISTNAME=	scponly-3.9
CATEGORIES=	shells
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sublimation.org/scponly/
COMMENT=	Tiny shell which only permits scp and sftp

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
PKG_SHELL=	${PREFIX}/bin/scponly

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
