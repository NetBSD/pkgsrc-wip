# $NetBSD: Makefile,v 1.2 2015/02/22 14:30:46 krytarowski Exp $

DISTNAME=	radare2-0.9.9
CATEGORIES=	devel
GIT_REPOSITORIES=	radare2
GIT_REPO.radare2=	git@github.com:radare/radare2.git
WRKSRC=		${WRKDIR}/radare2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.radare.org/
COMMENT=	Reverse engineering framework
LICENSE=	gnu-gpl-v3


HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-sysmagic
CONFIGURE_ARGS+=	--with-syscapstone
PKGCONFIG_OVERRIDE+=	pkgcfg/*.pc*
USE_TOOLS+=	gmake

.include "options.mk"

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
