# $NetBSD: Makefile,v 1.6 2015/04/25 12:34:35 krytarowski Exp $

GITHUB_PROJECT=	wklejto
DISTNAME=	0.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=napcok/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=napcok/wklejto/}
COMMENT=	Pastebin script for wklejto.org
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	gtar

WRKSRC=		${WRKDIR}/wklejto-0.1
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run expr:run gsed:run
# XXX: After merging gexpr patch with mk/ use this line
#USE_TOOLS+=	bash:run gexpr:run gsed:run

# XXX: After merging gexpr patch with mk/ remove the following line
DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	xclip-[0-9]*:../../x11/xclip

NO_BUILD=	YES

REPLACE_BASH+=	usr/bin/wklejto

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		usr/bin/wklejto
SUBST_SED.fix-paths=		-e 's,"/usr,"${PREFIX},g'

SUBST_CLASSES+=		gsed
SUBST_STAGE.gsed=	pre-configure
SUBST_MESSAGE.gsed=	Adjusting gsed path.
SUBST_FILES.gsed=	usr/bin/wklejto
SUBST_SED.gsed=		-e "s, sed , ${TOOLS_PATH.gsed} ,g"

# $ gexpr http://wklejto.org/w/b8125f30 : '^http://wklejto.org/w/[0-9a-f]\+'
# 29
# $ expr http://wklejto.org/w/b8125f30 : '^http://wklejto.org/w/[0-9a-f]\+'  
# 0
# I will check what happens later.. for now just use gexpr

SUBST_CLASSES+=		gexpr
SUBST_STAGE.gexpr=	pre-configure
SUBST_MESSAGE.gexpr=	Adjusting gexpr path.
SUBST_FILES.gexpr=	usr/bin/wklejto
SUBST_SED.gexpr=	-e "s,expr , ${PREFIX}/bin/gexpr ,g"
# XXX: After merging gexpr patch with mk/ use this line
#SUBST_SED.gexpr=	-e "s,expr ,${TOOLS_PATH.gexpr} ,g"

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/wklejto ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/usr/share/wklejto/lang-mappings.sed ${DESTDIR}${PREFIX}/share/wklejto/

.include "../../mk/bsd.pkg.mk"
