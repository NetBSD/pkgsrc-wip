# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:25 ykomatsu Exp $

DISTNAME=		logrotate-3.7.2-4.src.rpm
PKGNAME=		logrotate-3.7.2
CATEGORIES=		sysutils
MASTER_SITES=		http://download.fedora.redhat.com/pub/fedora/linux/core/development/SRPMS/
EXTRACT_SUFX=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# empty
COMMENT=		Daemon to rotate, compress, remove and mail system log files

BUILD_DEPENDS+=		rpm2pkg>=2.0:../../pkgtools/rpm2pkg

USE_TOOLS+=		gmake gzcat tar
NO_EXPORT_CPP=		yes
MAKE_ENV+=		"BASEDIR=${PREFIX}"
MAKE_ENV+=		"INSTALL_PROGRAM=${INSTALL_PROGRAM}"
MAKE_ENV+=		"INSTALL_MAN=${INSTALL_MAN}"
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

do-extract:
	rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DISTNAME}
	cd ${WRKDIR} ; ${GZCAT} ${WRKDIR}/${PKGNAME}.tar.gz | ${TAR} -xf -

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/logrotate.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/logrotate/logrotate.d
	${SED} -e 's|__PREFIX__|${PREFIX}|'		\
		< ${FILESDIR}/logrotate.conf.sample	\
		> ${PREFIX}/share/examples/logrotate/logrotate.conf.sample
	${INSTALL_DATA} ${FILESDIR}/syslog.sample	\
		${PREFIX}/share/examples/logrotate/logrotate.d/

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
