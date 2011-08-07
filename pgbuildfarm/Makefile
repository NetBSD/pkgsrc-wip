# $NetBSD: Makefile,v 1.2 2011/08/07 10:45:31 nthauvin Exp $
#

DISTNAME=		build-farm-4_5
PKGNAME=		pgbuildfarm-4.5
CATEGORIES=		databases
MASTER_SITES=		http://pgfoundry.org/frs/download.php/3028/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nico@orgrim.net
HOMEPAGE=		http://www.pgbuildfarm.org/
COMMENT=		PostgreSQL Build Farm client
LICENSE=		postgresql-license

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		scmgit-base>=1.6:../../devel/scmgit-base
DEPENDS+=		p5-libwww>=5.0:../../www/p5-libwww
DEPENDS+=		p5-Digest-SHA1>=2.13:../../security/p5-Digest-SHA1

WRKSRC=			${WRKDIR}/build-farm-4.5
NO_BUILD=		yes
USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run
AUTO_MKDIRS=		yes
REPLACE_PERL+=		${WRKSRC}/*.pl

EGDIR=			${PREFIX}/share/examples/pgbuildfarm
PMDIR=			${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/PGBuild
CONF_FILES=		${EGDIR}/build-farm.conf \
			${PKG_SYSCONFDIR}/build-farm.conf
PKG_SYSCONFSUBDIR=	pgbuildfarm

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	setnotes.pl update_personality.pl PGBuild/Options.pm
SUBST_SED.conf=		-e 's,build-farm.conf,${PKG_SYSCONFDIR}/build-farm.conf,'
SUBST_MESSAGE.conf=	Fixing default value for build-farm.conf

INSTALLATION_DIRS+= ${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}
INSTALLATION_DIRS+= ${PKG_SYSCONFDIR}

.include "../../lang/perl5/dirs.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PMDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/PGBuild/*.pm ${DESTDIR}${PMDIR}
	${INSTALL_DATA} ${WRKSRC}/build-farm.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
