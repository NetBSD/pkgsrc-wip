# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:25 thomasklausner Exp $
# FreeBSD Id: ports/shells/scponly/Makefile,v 1.1 2002/09/10 22:18:46 obraun Exp

DISTNAME=	scponly-3.7
CATEGORIES=	shells
MASTER_SITES=	http://www.sublimation.org/scponly/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sublimation.org/scponly/
COMMENT=	Tiny shell which only permits scp and sftp

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/sbin/scponly

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scponly ${PREFIX}/sbin

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
