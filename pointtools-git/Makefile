# $NetBSD$

DISTNAME=	pointtools-0.3
CATEGORIES=	misc
MASTER_SITES=	ftp://bitreich.org/releases/pointtools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/pointtools
COMMENT=	Simple point utilities to hold text presentations
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	pointtools
GIT_REPO.pointtools=	git://bitreich.org/pointtools/
WRKSRC=			${WRKDIR}/pointtools

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# getline, strlcpy

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-configure
SUBST_MESSAGE.makefile=	Adjusting config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS += ,'
SUBST_SED.makefile+=	-e '/^INCS/ s,^,\#,'
SUBST_SED.makefile+=	-e '/^LIBS/ s,^,\#,'
SUBST_SED.makefile+=	-e '/^CFLAGS/ s,-g,,'
SUBST_SED.makefile+=	-e '/^LDFLAGS/ s,-g,,'

USE_LANGUAGES=	c99

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
