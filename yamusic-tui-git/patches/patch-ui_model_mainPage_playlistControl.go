$NetBSD$

Guard pl.Albums[pl.SelectedAlbum] with an upper-bound check in
displayPlaylist. An ALBUMS playlist with an empty Albums list but
SelectedAlbum >= 0 otherwise indexes out of range and panics at
runtime (index out of range); it now falls back to the plain title.

--- ui/model/mainPage/playlistControl.go.orig	2026-10-06 15:01:33.041870456 +0300
+++ ui/model/mainPage/playlistControl.go	2026-10-06 18:21:13.916653760 +0300
@@ -319,7 +319,7 @@
 	case playlist.LOCAL:
 		m.tracklist.Title = "Cached tracks"
 	case playlist.ALBUMS:
-		if pl.SelectedAlbum >= 0 {
+		if pl.SelectedAlbum >= 0 && pl.SelectedAlbum < len(pl.Albums) {
 			album := pl.Albums[pl.SelectedAlbum]
 			title := style.TrackTitleStyle.Render(album.Title)
 			artists := style.TrackArtistStyle.Render(" (" + helpers.ArtistList(album.Artists) + ")")
