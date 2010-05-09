# $NetBSD: Makefile,v 1.26 2010/05/09 19:07:53 pettai Exp $
#

DISTNAME=	opendnssec-1.1.0rc2
CATEGORIES=	net security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-4Suite-[0-9]*:../../textproc/py-4Suite
DEPENDS+=	ldns>=1.6.4:../../net/ldns
BUILD_DEPENDS+=	CUnit-[0-9]*:../../devel/cunit

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	bash gmake
CONFIG_SHELL=	${BASH}
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		RUBY=${RUBY}

ODS_USER?=	opendnssec
ODS_GROUP?=	opendnssec

PKG_GROUPS=		${ODS_GROUP}
PKG_USERS=		${ODS_USER}:${ODS_GROUP}
PKG_GECOS.${ODS_USER}=	OpenDNSSEC user
PKG_HOME.${ODS_USER}=	${VARBASE}/opendnssec
PKG_SHELL.${ODS_USER}=	${SH}
PKG_USERS_VARS+=	ODS_USER
PKG_GROUPS_VARS+=	ODS_GROUP

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

pre-install:
	${MKDIR} ${DESTDIR}${PKG_SYSCONFDIR}/opendnssec

.include "../../lang/python/application.mk"
.include "../../devel/cunit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
