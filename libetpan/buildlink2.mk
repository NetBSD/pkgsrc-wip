# $NetBSD: buildlink2.mk,v 1.3 2004/02/02 18:22:07 dawszy Exp $
#
# This Makefile fragment is included by packages that use libetpan.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(LIBETPAN_BUILDLINK2_MK)
LIBETPAN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libetpan
BUILDLINK_DEPENDS.libetpan?=		libetpan>=0.32
BUILDLINK_PKGSRCDIR.libetpan?=		../../wip/libetpan

EVAL_PREFIX+=	BUILDLINK_PREFIX.libetpan=libetpan
BUILDLINK_PREFIX.libetpan_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libetpan+=	include/libetpan.h
BUILDLINK_FILES.libetpan+=	include/libetpan/carray.h
BUILDLINK_FILES.libetpan+=	include/libetpan/charconv.h
BUILDLINK_FILES.libetpan+=	include/libetpan/chash.h
BUILDLINK_FILES.libetpan+=	include/libetpan/cinthash.h
BUILDLINK_FILES.libetpan+=	include/libetpan/clist.h
BUILDLINK_FILES.libetpan+=	include/libetpan/data_message_driver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/generic_cache_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/imapdriver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/imapdriver_cached.h
BUILDLINK_FILES.libetpan+=	include/libetpan/imapdriver_cached_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/imapdriver_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/imapdriver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/imapstorage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/libetpan-config.h
BUILDLINK_FILES.libetpan+=	include/libetpan/libetpan.h
BUILDLINK_FILES.libetpan+=	include/libetpan/libetpan_version.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mail.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildir.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildir_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildirdriver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildirdriver_cached.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildirdriver_cached_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildirdriver_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildirdriver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildirstorage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildriver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildriver_errors.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildriver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/maildriver_types_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimap.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimap_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimap_socket.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimap_ssl.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimap_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimap_types_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimf.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimf_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimf_types_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailimf_write.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmbox.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmbox_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmessage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmessage_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmh.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime_content.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime_decode.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime_disposition.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime_types_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailmime_write.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailpop3.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailpop3_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailpop3_socket.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailpop3_ssl.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailpop3_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailsmtp.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailsmtp_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailsmtp_socket.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailsmtp_ssl.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailsmtp_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstorage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstorage_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstream.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstream_helper.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstream_low.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstream_socket.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstream_ssl.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailstream_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailthread.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mailthread_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mboxdriver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mboxdriver_cached.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mboxdriver_cached_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mboxdriver_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mboxdriver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mboxstorage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mhdriver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mhdriver_cached.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mhdriver_cached_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mhdriver_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mhdriver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mhstorage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mime_message_driver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/mmapstring.h
BUILDLINK_FILES.libetpan+=	include/libetpan/newsnntp.h
BUILDLINK_FILES.libetpan+=	include/libetpan/newsnntp_socket.h
BUILDLINK_FILES.libetpan+=	include/libetpan/newsnntp_ssl.h
BUILDLINK_FILES.libetpan+=	include/libetpan/newsnntp_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/nntpdriver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/nntpdriver_cached.h
BUILDLINK_FILES.libetpan+=	include/libetpan/nntpdriver_cached_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/nntpdriver_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/nntpdriver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/nntpstorage.h
BUILDLINK_FILES.libetpan+=	include/libetpan/pop3driver.h
BUILDLINK_FILES.libetpan+=	include/libetpan/pop3driver_cached.h
BUILDLINK_FILES.libetpan+=	include/libetpan/pop3driver_cached_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/pop3driver_message.h
BUILDLINK_FILES.libetpan+=	include/libetpan/pop3driver_types.h
BUILDLINK_FILES.libetpan+=	include/libetpan/pop3storage.h
BUILDLINK_FILES.libetpan+=	lib/libetpan.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"

BUILDLINK_TARGETS+=	libetpan-buildlink

libetpan-buildlink: _BUILDLINK_USE

.endif	# LIBETPAN_BUILDLINK2_MK
