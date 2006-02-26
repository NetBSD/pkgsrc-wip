# $NetBSD: Makefile,v 1.4 2006/02/26 12:33:38 obache Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	java-qdbm-1.0.0.${QDBM_VERSION}
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qdbm/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://qdbm.sourceforge.net/
COMMENT=	Java API of QDBM

MY_SUBDIR=	java
BUILD_DIRS=	${MY_SUBDIR:Q}
CONFIGURE_DIRS=	${MY_SUBDIR:Q}

GNU_CONFIGURE=	yes
TEST_TARGET=	check

PERL5_PACKLIST=	auto/Curia/.packlist auto/Depot/.packlist auto/Villa/.packlist
REPLACE_PERL+=	${MY_SUBDIR:Q}/curia/plcrtest ${MY_SUBDIR:Q}/depot/pldptest \
		${MY_SUBDIR:Q}/villa/plvltest

.include "../../databases/qdbm/buildlink3.mk"
.include "../../mk/java-vm.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=	pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR:Q}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
