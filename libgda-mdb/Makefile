# $NetBSD: Makefile,v 1.1.1.1 2012/05/02 08:44:16 noud4 Exp $
#

LIBGDA_PROVIDER=	mdb
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-mdb=${PREFIX}
CFLAGS+=		-DMDB_WITH_WRITE_SUPPORT

pre-build:
	#${CP} ${PREFIX}/lib/libintl* ${WRKDIR}/.buildlink/lib					# XXX
	${LN} -s ${WRKDIR}/.buildlink/lib/libmdb.0 ${WRKDIR}/.buildlink/lib/libmdb		# XXX
	${LN} -s ${WRKDIR}/.buildlink/lib/libmdbsql.0 ${WRKDIR}/.buildlink/lib/libmdbsql	# XXX

.include "../../wip/mdbtools/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"						# XXX
.include "../../mk/bsd.pkg.mk"
