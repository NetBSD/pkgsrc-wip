# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=	activation-1.1.1
PKGNAME=	java-gnujaf-1.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=classpathx/}
LICENSE=	gnu-gpl-v3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ftp.gnu.org/gnu/classpathx/
COMMENT=		GNU Java Activation Framework


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKE_JOBS_SAFE=		no

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
