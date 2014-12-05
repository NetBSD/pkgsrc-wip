# $NetBSD: Makefile,v 1.7 2014/12/05 11:53:47 thomasklausner Exp $

DISTNAME=	radare2-0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://www.radare.org/get/
EXTRACT_SUFX=	.tar.xz

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

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
