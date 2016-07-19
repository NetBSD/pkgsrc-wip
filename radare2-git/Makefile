# $NetBSD: Makefile,v 1.3 2015/03/21 21:01:51 krytarowski Exp $

DISTNAME=	radare2-0.10.5
CATEGORIES=	devel
GIT_REPOSITORIES=	radare2
GIT_REPO.radare2=	https://github.com/radare/radare2.git
WRKSRC=		${WRKDIR}/radare2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.radare.org/
COMMENT=	Reverse engineering framework
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-sysmagic
CONFIGURE_ARGS+=	--with-syscapstone
CONFIGURE_ARGS+=	--with-syszip
PKGCONFIG_OVERRIDE+=	pkgcfg/*.pc*
USE_TOOLS+=	gmake

# REPLACE_NODE?
REPLACE_INTERPRETER+=	node
REPLACE.node.old=	.*node[^ ]*
REPLACE.node.new=	${LOCALBASE}/bin/node
REPLACE_FILES.node=	shlr/www/m/vendors/fonts/iconjar-map.js

DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

.include "options.mk"

.include "../../devel/capstone/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
