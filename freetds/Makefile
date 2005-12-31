# $NetBSD: Makefile,v 1.1.1.1 2005/12/31 05:10:57 jlamwww Exp $
#
# To update this package to the latest FreeTDS snapshot, change the
# SNAPSHOT_VERS to match the version number in the directory name when
# freetds-current.tgz is unpacked.  Remember to run "make distclean" so
# that older tarballs are removed before "make fetch" is run.
#
SNAPSHOT_VERS=	0.64.dev.20051230

DISTNAME=	freetds-current
PKGNAME=	freetds-${SNAPSHOT_VERS:S/.dev./alpha/}
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/current/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

# We don't care about the distfile checksum for FreeTDS snapshots.
NO_CHECKSUM=		yes
WRKSRC=			${WRKDIR}/freetds-${SNAPSHOT_VERS}

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-tdsver=7.0
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

# no thread-safe resolver functions on NetBSD
CONFIGURE_ARGS+=	--disable-threadsafe

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} ETC=${EGDIR:Q} DOCDIR=doc/${PKGBASE:Q}

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES=	${EGDIR}/freetds.conf ${PKG_SYSCONFDIR}/freetds.conf
CONF_FILES+=	${EGDIR}/locales.conf ${PKG_SYSCONFDIR}/locales.conf
CONF_FILES+=	${EGDIR}/pool.conf ${PKG_SYSCONFDIR}/pool.conf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/.PLIST.doc

# Workaround a weird problem in the source Makefiles that prevents
# easily changing the installation directory for the documentation.
#
pre-build:
	cd ${WRKSRC}/doc/doc && ln -s freetds-[0-9]* ${PKGBASE:Q}

# Dynamically generate PLIST entries for the documentation.  This target
# may need to be modified for future FreeTDS releases.
#
${WRKDIR}/.PLIST.doc:
	{ cd ${WRKSRC}/doc/doc/freetds;					\
	  find reference userguide \( -type f -o -type l \) -print;	\
	  cd ${WRKSRC}/doc;						\
	  find images -name \*.gif -print;				\
	} | sed "s,^,share/doc/"${PKGBASE:Q}"/," | sort -u		\
	> ${.TARGET}
	{ cd ${WRKSRC}/doc/doc/freetds;					\
	  find reference userguide -type d -print;			\
	  ${ECHO} "images";						\
	} | sed "s,^,@dirrm share/doc/"${PKGBASE:Q}"/," | sort -ur	\
	>> ${.TARGET}
	${ECHO} "@dirrm share/doc/"${PKGBASE:Q} >> ${.TARGET}

.include "../../mk/bsd.pkg.mk"
