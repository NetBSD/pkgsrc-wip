# $NetBSD$

DISTNAME=	guile-colorized-0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=NalaGinrut/}
GITLAB_TAG=	v${PKGVERSION_NOREV}
# MASTER_SITES=	https://gitlab.com/NalaGinrut/guile-colorized/-/archive/v0.1/guile-colorized-v0.1.tar.gz
#GITLAB_TAG=	c4af182fe0e754ef9f094b472b588f6aa90a3b86

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://gitlab.com/NalaGinrut/guile-colorized/
COMMENT=	Colorized REPL for Guile
LICENSE=	gnu-gpl-v3

AUTO_MKDIRS=	yes
#WRKSRC=		${WRKDIR}/${DISTNAME:S/0.1/v0.1/}-${GITLAB_TAG}

# Skip Makefile install, as it just wants to copy to destdir directly.
# \todo: send patch for prefix support.
# \todo: should get properly compiled, but this is a no-issue.
do-install:
	${INSTALL_DATA} ${WRKSRC}/ice-9/colorized.scm ${DESTDIR}${PREFIX}/guile/2.2/share/guile/2.2/ice-9/

.include "../../lang/guile22/buildlink3.mk"
.include "../../wip/mk/gitlab.mk"
.include "../../mk/bsd.pkg.mk"
