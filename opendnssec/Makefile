# $NetBSD: Makefile,v 1.20 2010/01/17 12:03:29 thomasklausner Exp $
#

DISTNAME=	opendnssec-${VERSION}
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	iis-license

DEPENDS+=	${PYPKGPREFIX}-4Suite-[0-9]*:../../wip/py-4Suite
BUILD_DEPENDS+=	CUnit-[0-9]*:../../devel/cunit

LICENSE_FILE=	${FILESDIR}/iis-license

#SVN_REPOSITORIES=	opendnssec
#SVN_ROOT.opendnssec=	http://svn.opendnssec.org/tags/OpenDNSSEC-${VERSION}
#SVN_MODULE.opendnssec=	OpenDNSSEC
#NO_CHECKSUM=		yes
VERSION=		1.0.0rc2

PKG_DESTDIR_SUPPORT=	user-destdir
#PKG_INSTALLATION_TYPES= overwrite pkgviews

# XXX: Others might work
#ONLY_FOR_PLATFORM=	NetBSD-*-* Darwin-*-*

BUILD_DEFS+=	VARBASE

#USE_TOOLS+=	aclocal autoconf automake autoheader gmake gm4 perl
USE_TOOLS+=	bash gmake gm4 perl
CONFIG_SHELL=	${BASH}
USE_JAVA=	build
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		RUBY=${RUBY}

#WRKSRC=		${WRKDIR}/OpenDNSSEC
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
#PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14
.include "../../mk/java-vm.mk"
.endif

#pre-configure:
#	${CHMOD} u+x ${WRKSRC}/autogen.sh
#	cd ${WRKSRC} && ./autogen.sh

pre-install:
	${MKDIR} ${PKG_SYSCONFDIR}/opendnssec

.include "../../lang/python/application.mk"
#.include "../../devel/cunit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../databases/mysql5-client/buildlink3.mk"
#.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
