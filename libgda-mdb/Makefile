# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:38 asau Exp $
#

LIBGDA_PROVIDER=	mdb

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
