# $NetBSD: Makefile,v 1.24 2010/03/22 14:13:31 pettai Exp $
#

DISTNAME=	opendnssec-${VERSION}
CATEGORIES=	net security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	iis-license

DEPENDS+=	${PYPKGPREFIX}-4Suite-[0-9]*:../../textproc/py-4Suite
DEPENDS+=	ldns>=1.6.4:../../net/ldns
DEPENDS+=	${RUBY_PKGPREFIX}-dnsruby>=1.43:../../net/ruby-dnsruby
BUILD_DEPENDS+=	CUnit-[0-9]*:../../devel/cunit

LICENSE_FILE=	${FILESDIR}/iis-license

VERSION=		1.0.0

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	bash gmake gm4 perl
CONFIG_SHELL=	${BASH}
USE_JAVA=	build
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		RUBY=${RUBY}

EGDIR=			${PREFIX}/share/examples/opendnssec
ODS_SYSCONFDIR=		${PKG_SYSCONFDIR}/opendnssec

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/conf/Makefile.in
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths=	-e 's,@EGDIR@,${EGDIR},'

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CONF_FILES=	${EGDIR}/conf.xml.sample \
			${ODS_SYSCONFDIR}/conf.xml
CONF_FILES+=	${EGDIR}/kasp.xml.sample \
			${ODS_SYSCONFDIR}/kasp.xml
CONF_FILES+=	${EGDIR}/zonefetch.xml.sample \
			${ODS_SYSCONFDIR}/zonefetch.xml
CONF_FILES+=	${EGDIR}/zonelist.xml.sample \
			${ODS_SYSCONFDIR}/zonelist.xml

INSTALLATION_DIRS=	${EGDIR} ${ODS_SYSCONFDIR}
INSTALLATION_DIRS+=	share/opendnssec
INSTALLATION_DIRS+=	lib/opendnssec
INSTALLATION_DIRS+=	lib/opendnssec/signer
INSTALLATION_DIRS+=	lib/opendnssec/kasp_auditor
INSTALLATION_DIRS+=	${VARBASE}/opendnssec
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/tmp
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/signconf
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/signed
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/unsigned

.include "options.mk"

.if ${OPSYS} == "NetBSD"
.include "../../mk/java-vm.mk"
.endif

pre-install:
	${MKDIR} ${PKG_SYSCONFDIR}/opendnssec

.include "../../lang/python/application.mk"
#.include "../../devel/cunit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
