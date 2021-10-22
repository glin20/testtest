#include <stdio.h>
#include <ctype.h>
#include <time.h>

struct song_node *find_artist_song(struct song_node *head, char *artist){
	while (head){ 
		if (tolower(head -> artist) == tolower(artist)){
		return head;
	}
	return NULL
}

struct song_node *rand_song(struct song_node *head){
	srand(time(NULL));
	int r = rand() % sizeof(head) + 1;
	while (r){
		head = head -> next;
	}
	return head;
}

struct song_node *remove_song(struct song_node *head, char *artist, char *name){
	struct song_node *first = head;
  struct song_node *temp;
  int tmp = 1;
  while (head){
    if (tolower(head -> artist) == tolower(artist) && tolower(head -> name) == tolower(name) 			&& tmp != 1){
      temp -> next = head -> next;
      free(head);
    }
    if (tolower(head -> artist) == tolower(artist) && tolower(head -> name) == tolower(name) 			&& tmp == 1){
      temp = head -> next;
      first = temp;
      free(head);
    }
    temp = head;
    head = head -> next;
    tmp++;
  }
  return first;
}

struct free_list(struct song_node *head){
	struct song_node *first = head;
	struct virus *temp;
	while (head){
		temp = head;
		free(temp);
		head = head -> next;
	}
	return NULL;
}
