# $NetBSD: Makefile,v 1.1 2014/12/05 00:50:56 krytarowski Exp $

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

# Hack to walkaround INSTALL_LIB issues
#
# radare2 invented scripts for package build ("acr")
# Shared libraries are installed without +x permission and it's not obvious
# how to fix it properly.
# Go for chmod hack, being encouraged by usage of it in radare2.spec bundled
# with the upstream version of this software.
post-install:
	${RUN}${FIND} ${DESTDIR} -type f -name '*.so*' -exec ${CHMOD} 0755 {} \;

.include "../../wip/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
