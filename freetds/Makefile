# $NetBSD: Makefile,v 1.3 2006/01/31 03:45:30 rillig Exp $
#
# To use this package to track FreeTDS snapshots, just do:
#
#	make distclean && make install
#
# This will remove the old distfile to force fetching the latest one
# for installation.
#

# This package is perpetually at "alpha release 1" of the next release.
PKGNAME=	freetds-0.64alpha1

DISTNAME=	freetds-current
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

# We don't care about the distfile checksum for FreeTDS snapshots.
NO_CHECKSUM=		yes
WRKSRC_cmd=		${LS} -1d ${WRKDIR:Q}/${PKGNAME_NOREV:C/alpha.*//}.dev.* 2>/dev/null || echo ${WRKDIR:Q}/nonexistent
WRKSRC=			${WRKSRC_cmd:sh}

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv:Q}
CONFIGURE_ARGS+=	--with-tdsver=7.0
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}

# no thread-safe resolver functions on NetBSD
CONFIGURE_ARGS+=	--disable-threadsafe

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} ETC=${EGDIR:Q} DOCDIR=doc/${PKGBASE:Q}

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES=	${EGDIR:Q}/freetds.conf ${PKG_SYSCONFDIR:Q}/freetds.conf
CONF_FILES+=	${EGDIR:Q}/locales.conf ${PKG_SYSCONFDIR:Q}/locales.conf
CONF_FILES+=	${EGDIR:Q}/pool.conf ${PKG_SYSCONFDIR:Q}/pool.conf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/.PLIST.doc

# Workaround a weird problem in the source Makefiles that prevents
# easily changing the installation directory for the documentation.
#
pre-build:
	cd ${WRKSRC:Q}/doc/doc && ${LN} -s freetds-[0-9]* ${PKGBASE:Q}

# Dynamically generate PLIST entries for the documentation.  This target
# may need to be modified for future FreeTDS releases.
#
${WRKDIR}/.PLIST.doc:
	set -e;								\
	{ cd ${WRKSRC:Q}/doc/doc/freetds;				\
	  ${FIND} reference userguide \( -type f -o -type l \) -print;	\
	  cd ${WRKSRC:Q}/doc;						\
	  ${FIND} images -name \*.gif -print;				\
	} | ${SED} "s,^,share/doc/"${PKGBASE:Q}"/," | ${SORT} -u	\
	> ${.TARGET}
	set -e;								\
	{ cd ${WRKSRC:Q}/doc/doc/freetds;				\
	  ${FIND} reference userguide -type d -print;			\
	  ${ECHO} "images";						\
	} | ${SED} "s,^,@dirrm share/doc/"${PKGBASE:Q}"/," | ${SORT} -ur\
	>> ${.TARGET}
	${ECHO} "@dirrm share/doc/"${PKGBASE:Q} >> ${.TARGET}

.include "../../mk/bsd.pkg.mk"
