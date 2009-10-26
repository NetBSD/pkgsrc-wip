# $NetBSD: Makefile,v 1.12 2009/10/26 22:23:09 pettai Exp $
#

DISTNAME=	opendnssec-${VERSION}
CATEGORIES=	net security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	iis-license

DEPENDS+=	${PYPKGPREFIX}-4Suite:../../wip/py-4Suite

LICENSE_FILE=	${FILESDIR}/iis-license

USE_TOOLS+=     aclocal autoconf automake autoheader gmake gm4 perl
USE_JAVA=	build
USE_LIBTOOL=	yes

SVN_REPOSITORIES=	opendnssec
SVN_ROOT.opendnssec=	http://svn.opendnssec.org/tags/OpenDNSSEC-${VERSION}
SVN_MODULE.opendnssec=	OpenDNSSEC
VERSION=		1.0.0b4
NO_CHECKSUM=		yes

.include "options.mk"

# XXX: Others might work
#ONLY_FOR_PLATFORM=	NetBSD-*-* Darwin-*-*

PKG_DESTDIR_SUPPORT=    user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

WRKSRC=			${WRKDIR}/OpenDNSSEC
EGDIR=			${PREFIX}/share/examples/opendnssec

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/conf/Makefile.am
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@EGDIR@,${EGDIR},'

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.if ${OPSYS} == "NetBSD" 
#PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14
.include "../../mk/java-vm.mk"
.endif

CONF_FILES=	${EGDIR}/conf.xml.sample \
			${PKG_SYSCONFDIR}/opendnssec/conf.xml
CONF_FILES+=	${EGDIR}/kasp.xml.sample \
			${PKG_SYSCONFDIR}/opendnssec/kasp.xml
CONF_FILES+=	${EGDIR}/zonefetch.xml.sample \
			${PKG_SYSCONFDIR}/opendnssec/zonefetch.xml
CONF_FILES+=	${EGDIR}/zonelist.xml.sample \
			${PKG_SYSCONFDIR}/opendnssec/zonelist.xml

INSTALLATION_DIRS=	${EGDIR} ${PKG_SYSCONFDIR}/opendnssec
INSTALLATION_DIRS+=	${PREFIX}/opendnssec
INSTALLATION_DIRS+=	${VARBASE}/opendnssec
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/tmp
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/signconf
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/signed
INSTALLATION_DIRS+=	${VARBASE}/opendnssec/unsigned

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../devel/cunit/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
