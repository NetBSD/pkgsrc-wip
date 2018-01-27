# $NetBSD: Makefile,v 1.1 2014/12/09 22:47:32 krytarowski Exp $

SNAPSHOT=	0.20131024
VERSION=	5.4.14
UPSTREAMNAME=	rpm
PKGSRCNAME=	rpm5
DISTNAME=	${UPSTREAMNAME}-${VERSION}-${SNAPSHOT}
PKGNAME=	${PKGSRCNAME}-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://rpm5.org/files/${UPSTREAMNAME}/${UPSTREAMNAME}-${VERSION:R}/
EXTRACT_SUFX=	.src.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rpm5.org/
COMMENT=	The RPM Package Manager
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		autoconf213 bash:run gmake msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-db=${BDBBASE}

BDB_ACCEPTED=		db4 db5

# Needs help finding bdb.
BUILDLINK_TRANSFORM+=	rename:-ldb:${BDB_LIBS}


WRKSRC=		${WRKDIR}/${UPSTREAMNAME}-${VERSION}
CPU_OS_MACROS=	cpu-os-macros

pre-patch:
	${RUN} ( cd ${WRKDIR} && tar zxf ${UPSTREAMNAME}-${VERSION}.tar.gz )
	${RUN} ( cd ${WRKDIR} && \
	         mkdir ${CPU_OS_MACROS} && \
	         tar zxf ${CPU_OS_MACROS}.tar.gz -C ${CPU_OS_MACROS} )

pre-configure:
	${RUN} ( cd ${WRKSRC} && autoreconf --force --verbose -i )


RPM5_DBI_FILES=	Basenames Conflictname Dirnames Group Installtid Name Packages \
	        Providename Provideversion Requirename Requireversion Triggername \
		Filemd5s Pubkeys Sha1header Sigmd5 \
	        __db.001 __db.002 __db.003 __db.004 __db.005

RPM5_ETCDIR=		/etc/${PKGSRCNAME}
RPM5_LIBDIR=		/var/lib/${PKGSRCNAME}
RPM5_REPACKAGEDIR=	/var/spool/repackage-${PKGSRCNAME}
RPM5_RPMHOME=		/usr/lib/${PKGSRCNAME}

post-install:
	${RUN} install -d ${DESTDIR}${RPM5_ETCDIR}
	${RUN} install -d ${DESTDIR}${RPM5_LIBDIR}
	${RUN} install -d ${DESTDIR}${RPM5_REPACKAGEDIR}
.for i in ${DBI_FILES}
	${RUN} ${TOUCH} ${DESTDIR}${RPM5_LIBDIR}/${i}
.endfor
	${RUN} cp -r ${WRKDIR}/${CPU_OS_MACROS}/* -C ${DESTDIR}${RPM5_RPMHOME}

.include "../../security/beecrypt/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
